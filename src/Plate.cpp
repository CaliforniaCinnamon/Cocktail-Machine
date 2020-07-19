// 
// �������� �𸣰����� Stepper �ν��Ͻ��� ������ �ȵ�!! ����
// ���� ���鿡 �ִ� �ڵ带 ���� ���� �͵� ������ ����

#include "Plate.h"

//************* ������ �� �Ҹ��� �Լ� ****************//
Plate::Plate()
{

    Serial.println("������ �Լ� �Լ�"); //************************************************************** test

    position = Coord(0, 0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 2, 3, 4, 5);
    Stepper stepper_y(STEPS_PER_REVOLUTION, 6, 7, 8, 9);
    // parameter notation: steps per revolution, driver pin 1, driver pin 2, driver pin 3, driver pin 4

    // �����Ҵ� ���ְ� Ŭ������ ������ ��������� ����
    p_stepper_x = (Stepper*)malloc(sizeof(stepper_x));
    p_stepper_y = (Stepper*)malloc(sizeof(stepper_y));

    // ���彺ž�� �ɸ�� ����
}

Plate::~Plate()
{
    // �������� �Ҵ��� �� Stepper �� ������ ���� ����
    free(p_stepper_x);
    free(p_stepper_y);

    Serial.println("�Ҹ��� �Լ� �Լ�");

    // ���� Actuator Ŭ������ ��ӹ޾Ҵٸ� �װ� �����!
    // �켱�� ���ܸ��� �׽�Ʈ ���̹Ƿ� �ܼ��� ������ ���ְ���.
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
    ((Stepper*)p_stepper_x)->setSpeed(a_speed);
    ((Stepper*)p_stepper_y)->setSpeed(a_speed);
}


// ��ǥ ��ġ�� Coord ��Ʈ��Ʈ�� �Է����ָ� ���� ��ġ�� ���� �� ����ŭ ������.
void Plate::move_horizontally(Coord a_des_pos)
{

    Serial.println("move horizontally �Լ� �Լ�"); //************************************************************** test

      // ���ڷ� ��ǥ ��ǥ�� �ް� (a_des_pos)
      // �Ʒ� �Լ��� ���� ��ǥ�� �޾� (current_position)
    Coord current_position = get_current_position();

    // x����, y���� ���� ���̸� ����ϰ� �׸�ŭ �����δ�.
    // x ���� �̵�
    int x_diff = a_des_pos.pos_x - current_position.pos_x;

    Serial.println(x_diff);

    ((Stepper*)p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y ���� �̵�
    int y_diff = a_des_pos.pos_y - current_position.pos_y;

    Serial.println(y_diff);

    ((Stepper*)p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}


// ȣ��Ǹ� (0,0)���� ���ư���, ��ǥ�� �ʱ�ȭ��.
void Plate::move_to_initial_position()
{
    // �ʿ��� �÷��� & �ӵ� ���� �� �ʱ�ȭ
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1; // ���� �ʿ�!

    // x ������ �ʱ�ȭ
    while (!x_touch) {
        ((Stepper*)p_stepper_x)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y ������ �ʱ�ȭ
    while (!y_touch) {
        ((Stepper*)p_stepper_y)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}


// ���� �ǳ��ָ鼭 ȣ���ϸ�, �������Ͱ� �ö󰡰� �ش� �ð���ŭ ��ٷȴٰ� �������Ͱ� ������.
void Plate::push_dispenser(int a_amount) {
    return;
    // �������� Ŭ���� ��Ŭ��� �ؿͼ� work_pump �Լ� �ٷ� ����ϸ� ��.

}
