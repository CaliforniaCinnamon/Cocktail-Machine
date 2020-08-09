// Plate.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

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
    int STEPPER_DELAY = 2000;

    Coord position; // ���� �ڱ��� ��ġ
    
    const int PIN_ENDSTOP_X = 52;
    const int PIN_ENDSTOP_Y = 53;

    void CWmove(int steps, int dp, int sp);
    void CCWmove(int steps, int dp, int sp);

public:
    Plate();
	void move(int steps, int xy); // xy�� 0�̸� x����, 1�̸� y����
	void moveto(Coord a_des_pos);
    void moveto(int px, int py);
    Coord get_current_position();
    void move_to_initial_position();
    void set_stepper_speed(long a_speed);
    void push_dispenser(int a_amount);
};

#endif


/* ������ ���۷���:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/