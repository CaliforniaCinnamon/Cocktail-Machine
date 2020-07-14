// 
// �������� �𸣰����� Stepper �ν��Ͻ��� ������ �ȵ�!! ����
// ���� ���鿡 �ִ� �ڵ带 ���� ���� �͵� ������ ����

#include "Plate.h"

Coord Plate::get_current_position() {
    return position;
}


void Plate::set_stepper_speed(long a_speed) {
    this->stepper_x.setSpeed(a_speed);
    this->stepper_y.setSpeed(a_speed);
}


void Plate::move_horizontally(Coord a_des_pos)
{
    // ���ڷ� ��ǥ ��ǥ�� �ް� (a_des_pos)
    // �Ʒ� �Լ��� ���� ��ǥ�� �޾� (current_position)
    Coord current_position = get_current_position();

    // x����, y���� ���� ���̸� ����ϰ� �׸�ŭ �����δ�.
    // x ���� �̵�
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    stepper_x.step(x_diff);
    this->position.pos_x += x_diff;

    // y ���� �̵�
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    stepper_x.step(y_diff);
    this->position.pos_y += y_diff;
}


void Plate::move_to_initial_position()
{
    // �ʿ��� �÷��� & �ӵ� ���� �� �ʱ�ȭ
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1;

    // x ������ �ʱ�ȭ
    while (!x_touch) {
        stepper_x.step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y ������ �ʱ�ȭ
    while (!y_touch) {
        stepper_y.step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}

