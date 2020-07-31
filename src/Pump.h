// Pump.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Pump {
private:
	void start_pump(int pump_num);
	int cal_pump(int amount);
	int PIN_PUMP_1;  int PIN_PUMP_2;

public:
	void work_pump(int pump_num,int amount);
	Pump(int a, int b = 0) {//*********************************************************이거 9번째 pump때매 뒤에 default 0이라한건데...되겟지..?
		PIN_PUMP_1 = a;  PIN_PUMP_2 = b;
	}
	void stop_pump(int pump_num);
};


#endif


/*
사용 예시:
double i = 750;  양 mL 단위
Pump a;
a.work_pump(i);
*/