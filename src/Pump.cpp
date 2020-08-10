// 
// ok
// 

#if 1

#include "Pump.h"


int Pump::cal_pump(int amount, int pump_num) 
{
	//이거 배열안쓰고 다 600으로 해줘도 될것같음
	int pump_ratio[9] = { 600,600,600,600,600,600,600,600,600 }; // 펌프 얼마나 잘 나오는지?
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
	//800,600**1
	//800,600**2
	//800,600**3
	//800,600**4
	//1500**********5오렌지는 잘 안내려간다_바로 나옴
	//자몽은 아직 모른다6
	//2500**********사이다도 잘 안내려간다_바로 나옴
	
	//처음 시작
	switch (pump_num) {
	case 1:
		start_pump(pump_num);
		delay(800);
		stop_pump(pump_num);
		break;
	case 2:
		start_pump(pump_num);
		delay(800);
		stop_pump(pump_num);
		break;
	case 3:
		start_pump(pump_num);
		delay(800);
		stop_pump(pump_num);
		break;
	case 4:
		start_pump(pump_num);
		delay(800);
		stop_pump(pump_num);
		break;
	case 5:
		start_pump(pump_num);
		delay(1500);
		stop_pump(pump_num);
		break;
	case 6:
		start_pump(pump_num);
		delay(20000);
		stop_pump(pump_num);
		break;
	case 7:
		start_pump(pump_num);
		delay(2500);
		stop_pump(pump_num);
		break;
	case 8://unknown
		start_pump(pump_num);
		delay(20000);
		stop_pump(pump_num);
		break;
	case 9://unknown
		start_pump(pump_num);
		delay(20000);
		stop_pump(pump_num);
		break;
	}
	//15ml씩 나옴
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num));//변환 시간 입력
	stop_pump(pump_num);
}

#endif