// 
// 
// 

#if 1

#include "Plate.h"

//****************** private 지정자 함수 *******************//
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
    int dirPin = -1; // 아무것도 아니란 의미에서 -1
    int stepPin = -1;

    if (xy == 0) { // x 방향
        pinMode(7, OUTPUT);
        pinMode(6, OUTPUT);
        dirPin = 7;
        stepPin = 6;
    }
    else { // y방향
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




//************* 생성자 및 소멸자 함수 ****************//
Plate::Plate()
{
    // 엔드스탑의 핀모드 설정
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}


//****************** public 지정자 함수 ******************//

// 현재의 위치를 Coord로 리턴해줌.
Coord Plate::get_current_position()
{
    return position;
}


// 말그대로 스피드를 설정해줌.
void Plate::set_stepper_speed(long a_speed) {
    STEPPER_DELAY = a_speed;
}



void Plate::moveto(int px, int py) 
{
	Coord c(px, py);
	Plate::moveto(c);
}


void Plate::moveto(Coord a_des_pos) {
	
	//문제되는 구간의 디스펜서4개의 번호는
	//-------
	// 4 | 1
	//	 *(stir)
	// 3 | 2
	// | 는 x축방향
	//디스펜서_1의 (x위치, y위치)
	Coord disp_stir1(1, 0);//*************************직접 확인후수정
	//디스펜서_2의 (x위치, y위치)
	Coord disp_stir2(2, 0);
	//확인 후 추가


	// 인자로 목표 좌표를 받고 (a_des_pos)
	// 아래 함수로 현재 좌표를 받아 (current_position)
	Coord current_position = get_current_position();

	//x좌표 범위로 판별(주의_ material x좌표 설정해줄때 initial pos에서 멀수록 더 큰 값)
	if (a_des_pos.pos_x <= disp_stir2.pos_x) {

		// x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
		// x 방향 이동
		int x_diff = a_des_pos.pos_x - current_position.pos_x;
		move(x_diff, 0);
		this->position.pos_x += x_diff;

		// y 방향 이동
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff, 1);
		this->position.pos_y += y_diff;

	}

	else { // 주의해야 할 구간
		int ref_diff = 3;
		//x축 이동 -> y축 이동 -> x축 이동
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


// 호출되면 (0,0)으로 돌아가고, 좌표도 초기화됨.
void Plate::move_to_initial_position()
{
    // 얼음 장치에 안 걸리게 하기 위한 좌표
    moveto(1, 2); // 상수 설정 필요

    // note: 스위치 모양이 /(우상향) 이렇게 되어 있을 때 왼쪽부터 차례대로,
    // 인풋 핀, VCC, GND 순서대로 연결한다.
	const int MOVE_STEP = -1;
    

    // y 방향의 초기화
	while (digitalRead(53) == 0) {
		move(MOVE_STEP, 1);
	}
	// end of while (y)

    // x 방향의 초기화
	while (digitalRead(52) == 0) {
		move(MOVE_STEP, 0);
	}
	// end of while (x)
}


// 양을 건네주면서 호출하면, 액츄에이터가 올라가고 해당 시간만큼 기다렸다가 액츄에이터가 내려옴.
void Plate::push_dispenser(int a_amount)
{
    // 선언 및 초기화, 딜레이 타임 & 4개 상수 측정 완료
    Actuator a(30, 31);
    const int UP_TIME = 1800;
    const int DOWN_TIME = 1520;
    const int FULL_WAIT_TIME = 3000;
    const int HALF_WAIT_TIME = 800;
    int num_full_push = a_amount / 30;
    int num_half_push = (a_amount % 30) / 15;

    // 작동 코드 (한번 실행 될 때마다 30mL씩 나옴)
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