// 
// ok
// 

#if 1

#include "Pump.h"


int Pump::cal_pump(int amount, int pump_num) 
{
	int pump_ratio[9] = { 1,2,3,4,5,6,7,8,9 }; // 펌프 얼마나 잘 나오는지? @@@@@@@@@@@@@@@@@@@@@@@@@@@@
	int pump_time = amount * pump_ratio[pump_num - 1]; //양->초
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
		digitalWrite(PIN_PUMP_1, HIGH);
		digitalWrite(PIN_PUMP_2, HIGH);
	}
}


void Pump::work_pump(int pump_num, int amount) {
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num));//변환 시간 입력
	stop_pump(pump_num);
}

#endif