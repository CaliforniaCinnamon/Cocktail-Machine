// 
// ok
// 

#if 1

#include "Pump.h"


int Pump::cal_pump(int amount, int pump_num) 
{
	int pump_ratio[9] = { 1,2,3,4,5,6,7,8,9 }; // ���� �󸶳� �� ��������? @@@@@@@@@@@@@@@@@@@@@@@@@@@@
	int pump_time = amount * pump_ratio[pump_num - 1]; //��->��
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
		digitalWrite(PIN_PUMP_1, HIGH);
		digitalWrite(PIN_PUMP_2, HIGH);
	}
}


void Pump::work_pump(int pump_num, int amount) {
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num));//��ȯ �ð� �Է�
	stop_pump(pump_num);
}

#endif