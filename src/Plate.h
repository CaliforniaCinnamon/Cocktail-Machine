// Plate.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Stepper.h> 
#include "Actuator.h"

//************* Coord ��Ʈ��Ʈ ���� ******************//
struct Coord {
    int pos_x, pos_y;
    Coord() { pos_x = 0;  pos_y = 0; }
    Coord(int ax, int ay) {
        pos_x = ax;  pos_y = ay;
    }
    Coord& set(int ax = 0, int ay = 0) {
        pos_x = ax;  pos_y = ay;
    }
};
//***************************************************//




class Plate {
private:
    const int STEPS_PER_REVOLUTION = 200;
    int STEPPER_SPEED = 30;

    Coord position; // ���� �ڱ��� ��ġ

    // �� �ѹ��� ������ �Լ����� ���� �����ϴ°� ����ϱ�? - ���� �ʿ�
    const int PIN_ENDSTOP_X = 12;
    const int PIN_ENDSTOP_Y = 13;
    const int PIN_ENDSTOP_Z = 14;

    const int PIN_ACTUATOR_A = 12345;
    const int PIN_ACTUATOR_B = 67890;

    // void�� �����͸� ����ؼ�, Steper�� �����ϰ� �� �ּҸ� ����� �Ҵ��սô�.
    Stepper* p_stepper_x;
    Stepper* p_stepper_y;

    // �������� ���� �ڵ嵵 �߰��ؾ���.
    //=>���͵���̺� �߰��ؾ��Ѵٴ� ����??
    //���� ��� �ؾ��� �� �����ϴ� �ϴ� �ɹ�ȣ�� ����

    /* ���̸� �ٲ���ҵ�
    const int MDPIN_1 = 4;//motordrive_1�̶�� ��..��
    const int MDPIN_2 = 5;
    const int VPIN = 6;//�ӵ�(velocity) pwm ���� ��
    */



public:
    Plate();
    ~Plate();

    Coord get_current_position();
    void move_to(Coord a_des_pos);
    void move_to(int px, int py); // �Լ� �������̵�
    void move_to_initial_position();
    void set_stepper_speed(long a_speed);
    void push_dispenser(int a_amount);
};

#endif


/* ������ ���۷���:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/