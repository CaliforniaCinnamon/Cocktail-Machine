// 
// ok
// 

#if 1

#include "Pump.h"


//750ml준다고 하고 1초에 물 10ml나온다 가정
inline int Pump::cal_pump(int amount) 
{
	const int amount_per_sec_ratio = 10;
	int pump_time = amount / amount_per_sec_ratio; //양->초
	return pump_time;
}


void Pump::start_pump(int pump_num) 
{
	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, LOW);//LOW가 작동
	}
	else {
		digitalWrite(PIN_PUMP_1, HIGH);//서로 값이 달라야 정방향, 약하면 1,2 바꾸기
		digitalWrite(PIN_PUMP_2, LOW);
	}
	
}


void Pump::stop_pump(int pump_num) 
{
	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, HIGH);//HIGH가 멈춤
	}
	else {
		digitalWrite(PIN_PUMP_1, LOW);
		digitalWrite(PIN_PUMP_2, LOW);
	}
}


void Pump::work_pump(int pump_num, int amount) {
	start_pump(pump_num);
	delay(cal_pump(amount));//변환 시간 입력
	stop_pump(pump_num);
}

#endif