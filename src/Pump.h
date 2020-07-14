// Pump.h

#ifndef _PUMP_h
#define _PUMP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Pump {
private:
	void start_pump();
	void stop_pump();
	double cal_pump(double amount);
	int PIN_PUMP_1;  int PIN_PUMP_2;

public:
	void work_pump(double amount);
	Pump(int a, int b) {
		PIN_PUMP_1 = a;  PIN_PUMP_2 = b;
	}
};


#endif


/*
��� ����:
double i = 750;  �� mL ����
Pump a;
a.work_pump(i);
*/