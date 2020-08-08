// 
// 
// 

#if 1

#include "Plate.h"

//************* 생성자 및 소멸자 함수 ****************//
Plate::Plate()
{
    position = Coord(0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 40, 41, 42, 43);
    Stepper stepper_y(STEPS_PER_REVOLUTION, 6, 7, 8, 9);

    stepper_x.setSpeed(STEPPER_SPEED);
    stepper_y.setSpeed(STEPPER_SPEED);
    // parameter notation: 
    // steps per revolution, driver pin 1, driver pin 2, driver pin 3, driver pin 4

    // 동적할당 해주고 클래스의 포인터 멤버변수에 대입
    p_stepper_x = (Stepper*)malloc(sizeof(stepper_x));
    p_stepper_y = (Stepper*)malloc(sizeof(stepper_y));

    *(p_stepper_x) = stepper_x;
    *(p_stepper_y) = stepper_y;

    // 엔드스탑의 핀모드 설정
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}

Plate::~Plate()
{ // 동적으로 할당해 준 Stepper 의 해제를 위해 존재  
    free(p_stepper_x);
    free(p_stepper_y);
}
//******************************************************//



//****************** public 지정자 함수 ******************//

// 현재의 위치를 Coord로 리턴해줌.
Coord Plate::get_current_position()
{
    return position;
}


// 말그대로 스피드를 설정해줌.
void Plate::set_stepper_speed(long a_speed) {
    (p_stepper_x)->setSpeed(a_speed);
    (p_stepper_y)->setSpeed(a_speed);
}


// 목표 위치를 Coord 스트럭트로 입력해주면 현재 위치에 따라 그 차만큼 움직임.
void Plate::move_to(Coord a_des_pos)
{
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
		(p_stepper_x)->step(x_diff);
		this->position.pos_x += x_diff;

		// y 방향 이동
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		(p_stepper_y)->step(y_diff);
		this->position.pos_y += y_diff;
	
	}

	else {
		int ref_diff = 3;
		//x축 이동 -> y축 이동 -> x축 이동
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
		move(x_diff);
		this->position.pos_x += x_diff;

		// y 방향 이동
		int y_diff = a_des_pos.pos_y - current_position.pos_y;
		move(y_diff);
		this->position.pos_y += y_diff;

	}

	else {
		int ref_diff = 3;
		//x축 이동 -> y축 이동 -> x축 이동
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
    // 인자의 인트를 받아 목표 좌표로 설정
    Coord a_des_pos(px, py);
    // 아래 함수로 현재 좌표를 받아 (current_position)
    Coord current_position = get_current_position();

    // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
    // x 방향 이동
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    (p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y 방향 이동
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    (p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}


// 호출되면 (0,0)으로 돌아가고, 좌표도 초기화됨.
void Plate::move_to_initial_position()
{

    // note: 스위치 모양이 /(우상향) 이렇게 되어 있을 때 왼쪽부터 차례대로,
    // 인풋 핀, VCC, GND 순서대로 연결한다.

    // 필요한 플래그 & 속도 선언 및 초기화
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1; // 설정 필요!

    // x 방향의 초기화
    while (!x_touch) {
        if (digitalRead(PIN_ENDSTOP_X)) {
            x_touch = true;
        }
        else {
            this->position.pos_x -= move_speed;
            (p_stepper_x)->step(move_speed);
        }
    } // end of while (x)

    // y 방향의 초기화
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