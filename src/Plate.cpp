// 
// 
// 

#if 1

#include "Plate.h"

//************* ������ �� �Ҹ��� �Լ� ****************//
Plate::Plate()
{
    position = Coord(0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 40, 41, 42, 43);
    Stepper stepper_y(STEPS_PER_REVOLUTION, 6, 7, 8, 9);

    stepper_x.setSpeed(STEPPER_SPEED);
    stepper_y.setSpeed(STEPPER_SPEED);
    // parameter notation: 
    // steps per revolution, driver pin 1, driver pin 2, driver pin 3, driver pin 4

    // �����Ҵ� ���ְ� Ŭ������ ������ ��������� ����
    p_stepper_x = (Stepper*)malloc(sizeof(stepper_x));
    p_stepper_y = (Stepper*)malloc(sizeof(stepper_y));

    *(p_stepper_x) = stepper_x;
    *(p_stepper_y) = stepper_y;

    // ���彺ž�� �ɸ�� ����
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}

Plate::~Plate()
{ // �������� �Ҵ��� �� Stepper �� ������ ���� ����  
    free(p_stepper_x);
    free(p_stepper_y);
}
//******************************************************//



//****************** public ������ �Լ� ******************//

// ������ ��ġ�� Coord�� ��������.
Coord Plate::get_current_position()
{
    return position;
}


// ���״�� ���ǵ带 ��������.
void Plate::set_stepper_speed(long a_speed) {
    (p_stepper_x)->setSpeed(a_speed);
    (p_stepper_y)->setSpeed(a_speed);
}


// ��ǥ ��ġ�� Coord ��Ʈ��Ʈ�� �Է����ָ� ���� ��ġ�� ���� �� ����ŭ ������.
void Plate::move_to(Coord a_des_pos)
{
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
		(p_stepper_x)->step(x_diff);
		this->position.pos_x += x_diff;

		// y ���� �̵�
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		(p_stepper_y)->step(y_diff);
		this->position.pos_y += y_diff;
	
	}

	else {
		int ref_diff = 3;
		//x�� �̵� -> y�� �̵� -> x�� �̵�
		int x_diff = a_des_pos.pos_x - ref_diff;
		(p_stepper_x)->step(x_diff);
		this->position.pos_x += x_diff;

		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		(p_stepper_y)->step(y_diff);
		this->position.pos_y += y_diff;

		int x_diff = a_des_pos.pos_x - current_position.pos_x;
		(p_stepper_x)->step(x_diff);
		this->position.pos_x += x_diff;
		
	}
}
//*****************************************************************************
void Plate::CWmove(int steps) {
	digitalWrite(dirPin, HIGH);
	for (int i = 0; i < steps; i++) {
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(1000);
	}
}
void Plate::CCWmove(int steps) {
	digitalWrite(dirPin, LOW);
	for (int i = 0; i < steps; i++) {
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(1000);
	}
}
void Plate::move(int steps) {
	if (steps >= 0) {
		CWmove(steps);
	}
	else {
		CCWmove(abs(steps));
	}
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
		move(x_diff);
		this->position.pos_x += x_diff;

		// y ���� �̵�
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff);
		this->position.pos_y += y_diff;

	}

	else {
		int ref_diff = 3;
		//x�� �̵� -> y�� �̵� -> x�� �̵�
		int x_diff = a_des_pos.pos_x - ref_diff;
		move(x_diff);
		this->position.pos_x += x_diff;

		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff);
		this->position.pos_y += y_diff;

		int x_diff = a_des_pos.pos_x - current_position.pos_x;
		move(x_diff);
		this->position.pos_x += x_diff;

	}

}

//*****************************************************************************

void Plate::move_to(int px, int py)
{
    // ������ ��Ʈ�� �޾� ��ǥ ��ǥ�� ����
    Coord a_des_pos(px, py);
    // �Ʒ� �Լ��� ���� ��ǥ�� �޾� (current_position)
    Coord current_position = get_current_position();

    // x����, y���� ���� ���̸� ����ϰ� �׸�ŭ �����δ�.
    // x ���� �̵�
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    (p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y ���� �̵�
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    (p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}


// ȣ��Ǹ� (0,0)���� ���ư���, ��ǥ�� �ʱ�ȭ��.
void Plate::move_to_initial_position()
{

    // note: ����ġ ����� /(�����) �̷��� �Ǿ� ���� �� ���ʺ��� ���ʴ��,
    // ��ǲ ��, VCC, GND ������� �����Ѵ�.

    // �ʿ��� �÷��� & �ӵ� ���� �� �ʱ�ȭ
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1; // ���� �ʿ�!

    // x ������ �ʱ�ȭ
    while (!x_touch) {
        if (digitalRead(PIN_ENDSTOP_X)) {
            x_touch = true;
        }
        else {
            this->position.pos_x -= move_speed;
            (p_stepper_x)->step(move_speed);
        }
    } // end of while (x)

    // y ������ �ʱ�ȭ
    while (!y_touch) {
        if (digitalRead(PIN_ENDSTOP_Y)) {
            y_touch = true;
        }
        else {
            this->position.pos_y -= move_speed;
            (p_stepper_y)->step(move_speed);
        }
    } // end of while (y)

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