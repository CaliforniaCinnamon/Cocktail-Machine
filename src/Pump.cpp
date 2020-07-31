// 
// ok
// 

#if 1

#include "Pump.h"


//750ml�شٰ� �ϰ� 1�ʿ� �� 10ml���´� ����
inline int Pump::cal_pump(int amount) 
{
	const int amount_per_sec_ratio = 10;
	int pump_time = amount / amount_per_sec_ratio; //��->��
	return pump_time;
}


void Pump::start_pump(int pump_num) 
{
	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, LOW);//LOW�� �۵�
	}
	else {
		digitalWrite(PIN_PUMP_1, HIGH);//���� ���� �޶�� ������, ���ϸ� 1,2 �ٲٱ�
		digitalWrite(PIN_PUMP_2, LOW);
	}
	
}


void Pump::stop_pump(int pump_num) 
{
	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, HIGH);//HIGH�� ����
	}
	else {
		digitalWrite(PIN_PUMP_1, LOW);
		digitalWrite(PIN_PUMP_2, LOW);
	}
}


void Pump::work_pump(int pump_num, int amount) {
	start_pump(pump_num);
	delay(cal_pump(amount));//��ȯ �ð� �Է�
	stop_pump(pump_num);
}

#endif