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
	int cal_pump(int amount, int pump_num);
	int PIN_PUMP_1;  int PIN_PUMP_2;

public:
	void work_pump(int pump_num,int amount);
	Pump(int a, int b = 0) {
		PIN_PUMP_1 = a;  PIN_PUMP_2 = b;
	}
	void stop_pump(int pump_num);
};


#endif