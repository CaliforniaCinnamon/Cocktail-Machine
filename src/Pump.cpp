// 
// ok
// 

#if 1

#include "Pump.h"


//*************************** private 지정자 함수들 +*****************//
void Pump::set_pin_num(int a_pump_num)
{
	switch (a_pump_num) {
	case 1:
		PIN_PUMP_1 = 30; break;
	case 2:
		PIN_PUMP_1 = 31; break;
	case 3:
		PIN_PUMP_1 = 32; break;
	case 4:
		PIN_PUMP_1 = 33; break;
	case 5:
		PIN_PUMP_1 = 34; break;
	case 6:
		PIN_PUMP_1 = 35; break;
	case 7:
		PIN_PUMP_1 = 36; break;
	case 8:
		PIN_PUMP_1 = 37; break;
	case 9:
		PIN_PUMP_1 = 38;  PIN_PUMP_2 = 39;  break;
	}
}


int Pump::cal_pump(int amount, int pump_num) 
{
	int pump_ratio[9] = { 1,2,3,4,5,6,7,8,9 }; // 펌프 얼마나 잘 나오는지?
	int pump_time = amount * pump_ratio[pump_num - 1]; //양->초
	return pump_time;
}


void Pump::start_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // 펌프 공용 인스턴스의 핀 번호 설정

	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, LOW);//LOW가 작동
	}
	else {
		digitalWrite(PIN_PUMP_1, HIGH);//서로 값이 달라야 정방향, 약하면 1,2 바꾸기
		digitalWrite(PIN_PUMP_2, LOW);
	}
	
}


//******************************* public 지정자 함수 *****************************//


void Pump::stop_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // 펌프 공용 인스턴스의 핀 번호 설정

	if (pump_num != 8) { // 0~7 
		digitalWrite(PIN_PUMP_1, HIGH); //HIGH가 멈춤
	}
	else { // 8 (9번재 펌프)
		digitalWrite(PIN_PUMP_1, HIGH);
		digitalWrite(PIN_PUMP_2, HIGH);
	}
}


void Pump::work_pump(int pump_num, int amount) 
{
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num)); //변환 시간 입력
	stop_pump(pump_num);
}

#endif