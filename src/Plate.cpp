// 
// 
// 

#if 1

#include "Plate.h"

//****************** private ������ �Լ� *******************//
void Plate::CWmove(int steps, int dirPin, int stepPin)
{
    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(STEPPER_DELAY);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(STEPPER_DELAY);
    }
}


void Plate::CCWmove(int steps, int dirPin, int stepPin)
{
    digitalWrite(dirPin, LOW);
    for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(STEPPER_DELAY);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(STEPPER_DELAY);
    }
}


void Plate::move(int steps, int xy)
{
    int dirPin = -1; // �ƹ��͵� �ƴ϶� �ǹ̿��� -1
    int stepPin = -1;

    if (xy == 0) { // x ����
        pinMode(7, OUTPUT);
        pinMode(6, OUTPUT);
        dirPin = 7;
        stepPin = 6;
    }
    else { // y����
        pinMode(9, OUTPUT);
        pinMode(8, OUTPUT);
        dirPin = 9;
        stepPin = 8;
    }


    if (steps >= 0) {
        CWmove(steps, dirPin, stepPin);
    }
    else {
        CCWmove(abs(steps), dirPin, stepPin);
    }
}




//************* ������ �� �Ҹ��� �Լ� ****************//
Plate::Plate()
{
    // ���彺ž�� �ɸ�� ����
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}


//****************** public ������ �Լ� ******************//

// ������ ��ġ�� Coord�� ��������.
Coord Plate::get_current_position()
{
    return position;
}


// ���״�� ���ǵ带 ��������.
void Plate::set_stepper_speed(long a_speed) {
    STEPPER_DELAY = a_speed;
}



void Plate::moveto(int px, int py) 
{
	Coord c(px, py);
	Plate::moveto(c);
}


void Plate::moveto(Coord a_des_pos) {
	
	//�����Ǵ� ������ ���漭4���� ��ȣ��
	//-------
	// 4 | 1
	//	 *(stir)
	// 3 | 2
	// | �� x�����
	//���漭_1�� (x��ġ, y��ġ)
	Coord disp_stir1(1, 0);//*************************���� Ȯ���ļ���
	//���漭_2�� (x��ġ, y��ġ)
	Coord disp_stir2(2, 0);
	//Ȯ�� �� �߰�


	// ���ڷ� ��ǥ ��ǥ�� �ް� (a_des_pos)
	// �Ʒ� �Լ��� ���� ��ǥ�� �޾� (current_position)
	Coord current_position = get_current_position();

	//x��ǥ ������ �Ǻ�(����_ material x��ǥ �������ٶ� initial pos���� �ּ��� �� ū ��)
	if (a_des_pos.pos_x <= disp_stir2.pos_x) {

		// x����, y���� ���� ���̸� ����ϰ� �׸�ŭ �����δ�.
		// x ���� �̵�
		int x_diff = a_des_pos.pos_x - current_position.pos_x;
		move(x_diff, 0);
		this->position.pos_x += x_diff;

		// y ���� �̵�
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff, 1);
		this->position.pos_y += y_diff;

	}

	else { // �����ؾ� �� ����
		int ref_diff = 3;
		//x�� �̵� -> y�� �̵� -> x�� �̵�
		int x_diff = a_des_pos.pos_x - ref_diff;
		move(x_diff, 0);
		this->position.pos_x += x_diff;

		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff, 1);
		this->position.pos_y += y_diff;

		int x_diff = a_des_pos.pos_x - current_position.pos_x;
		move(x_diff, 0);
		this->position.pos_x += x_diff;

	}

}


// ȣ��Ǹ� (0,0)���� ���ư���, ��ǥ�� �ʱ�ȭ��.
void Plate::move_to_initial_position()
{
    // ���� ��ġ�� �� �ɸ��� �ϱ� ���� ��ǥ
    moveto(1, 2); // ��� ���� �ʿ�

    // note: ����ġ ����� /(�����) �̷��� �Ǿ� ���� �� ���ʺ��� ���ʴ��,
    // ��ǲ ��, VCC, GND ������� �����Ѵ�.
	const int MOVE_STEP = -1;
    

    // y ������ �ʱ�ȭ
	while (digitalRead(53) == 0) {
		move(MOVE_STEP, 1);
	}
	// end of while (y)

    // x ������ �ʱ�ȭ
	while (digitalRead(52) == 0) {
		move(MOVE_STEP, 0);
	}
	// end of while (x)
}


// ���� �ǳ��ָ鼭 ȣ���ϸ�, �������Ͱ� �ö󰡰� �ش� �ð���ŭ ��ٷȴٰ� �������Ͱ� ������.
void Plate::push_dispenser(int a_amount)
{
    // ���� �� �ʱ�ȭ, ������ Ÿ�� & 4�� ��� ���� �Ϸ�
    Actuator a(30, 31);
    const int UP_TIME = 1800;
    const int DOWN_TIME = 1520;
    const int FULL_WAIT_TIME = 3000;
    const int HALF_WAIT_TIME = 800;
    int num_full_push = a_amount / 30;
    int num_half_push = (a_amount % 30) / 15;

    // �۵� �ڵ� (�ѹ� ���� �� ������ 30mL�� ����)
    for (int i = 0; i < num_full_push; i++) {
        a.up();
        delay(UP_TIME);

        a.idle();
        delay(FULL_WAIT_TIME);

        a.down();
        delay(DOWN_TIME);

        a.idle();
    }

    if (num_half_push) {
        a.up();
        delay(UP_TIME);

        a.idle();
        delay(HALF_WAIT_TIME);

        a.down();
        delay(DOWN_TIME);

        a.idle();
    }

}


#endif