// 
// ok
// 

#if 1

#include "Pump.h"


//*************************** private ������ �Լ��� +*****************//
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
	int pump_ratio[9] = { 1,2,3,4,5,6,7,8,9 }; // ���� �󸶳� �� ��������?
	int pump_time = amount * pump_ratio[pump_num - 1]; //��->��
	return pump_time;
}


void Pump::start_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // ���� ���� �ν��Ͻ��� �� ��ȣ ����

	if (pump_num != 8) {
		digitalWrite(PIN_PUMP_1, LOW);//LOW�� �۵�
	}
	else {
		digitalWrite(PIN_PUMP_1, HIGH);//���� ���� �޶�� ������, ���ϸ� 1,2 �ٲٱ�
		digitalWrite(PIN_PUMP_2, LOW);
	}
	
}


//******************************* public ������ �Լ� *****************************//


void Pump::stop_pump(int pump_num) 
{
	this->set_pin_num(pump_num); // ���� ���� �ν��Ͻ��� �� ��ȣ ����

	if (pump_num != 8) { // 0~7 
		digitalWrite(PIN_PUMP_1, HIGH); //HIGH�� ����
	}
	else { // 8 (9���� ����)
		digitalWrite(PIN_PUMP_1, HIGH);
		digitalWrite(PIN_PUMP_2, HIGH);
	}
}


void Pump::work_pump(int pump_num, int amount) 
{
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num)); //��ȯ �ð� �Է�
	stop_pump(pump_num);
}

#endif