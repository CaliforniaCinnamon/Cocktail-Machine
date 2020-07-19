// Plate.h

#ifndef _PLATE_h
#define _PLATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Stepper.h> 


Stepper stepper_x(200, 1,2,3,4);
Stepper stepper_y(200, 1, 2, 3, 4);

/*
extern Stepper stepper_x(200, 1,2,3,4);
extern Stepper stepper_y(200, 1, 2, 3, 4);
*/

struct Coord {
	int pos_x, pos_y, pos_z;
	Coord() { pos_x = 0;  pos_y = 0;  pos_z = 0; }
	Coord(int ax, int ay, int az) {
		pos_x = ax;  pos_y = ay;  pos_z = az;
	}
	Coord& set(int ax = 0, int ay = 0, int az = 0) {
		pos_x = ax;  pos_y = ay;  pos_z = az;
	}
};

class Plate {
private:
	const static int STEPS_PER_REVOLUTION = 200;
	const static int STEPPER_SPEED = 30;
	 

	Coord position;

	const int PIN_ENDSTOP_X = 1;
	const int PIN_ENDSTOP_Y = 2;
	const int PIN_ENDSTOP_Z = 3;

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
	//�ƴѰͰ���..�ٵ� �̰� �ۿ� �ȵ� ���� ���� �����ϰ� �ؿ� �������� extern ���̴°žƴѰ� �ٵ� ã�ƺ��� class instance�� extern�ǵ����̸� ��������� ��
	Stepper stepper_x;
	Stepper stepper_y;
	
	Coord get_current_position();
	void move_horizontally(Coord a_des_pos);
	void move_to_initial_position();
	void set_stepper_speed(long a_speed);
	void push_dispenser(double a_amount);
};

inline Plate::Plate() {
	position = Coord(0, 0, 0);
}


#endif


/* ������ ���۷���:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/