// 
// �������� �𸣰����� Stepper �ν��Ͻ��� ������ �ȵ�!! ����
// ���� ���鿡 �ִ� �ڵ带 ���� ���� �͵� ������ ����

#include "Plate.h"

//************* ������ �� �Ҹ��� �Լ� ****************//
Plate::Plate()
{
    position = Coord(0, 0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 2, 3, 4, 5);
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
{
    // �������� �Ҵ��� �� Stepper �� ������ ���� ����
    free(p_stepper_x);
    free(p_stepper_y);
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
    (p_stepper_x)->setSpeed(a_speed);
    (p_stepper_y)->setSpeed(a_speed);
}


// ��ǥ ��ġ�� Coord ��Ʈ��Ʈ�� �Է����ָ� ���� ��ġ�� ���� �� ����ŭ ������.
void Plate::move_to(Coord a_des_pos)
{
    // ���ڷ� ��ǥ ��ǥ�� �ް� (a_des_pos)
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
        (p_stepper_x)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y ������ �ʱ�ȭ
    while (!y_touch) {
        (p_stepper_y)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}


// ���� �ǳ��ָ鼭 ȣ���ϸ�, �������Ͱ� �ö󰡰� �ش� �ð���ŭ ��ٷȴٰ� �������Ͱ� ������.
void Plate::push_dispenser(int a_amount)
{
    // ���� �� �ʱ�ȭ, ������ Ÿ��
    Actuator a(PIN_ACTUATOR_A, PIN_ACTUATOR_B);
    const int SECONDS_PER_AMOUNT = 10;  // ************* ���� �ʿ�!
    int delay_time = a_amount * 1000 / SECONDS_PER_AMOUNT;
    bool z_touch = false;

    // �۵� �ڵ�
    a.up();
    delay(delay_time);
    a.down();

    // �� ���� �����ϸ� �������� �ΰ� ���� ����
    while (!z_touch) {
        if (digitalRead(PIN_ENDSTOP_Z)) {
            a.idle();
            z_touch = true;
        }
    }

}