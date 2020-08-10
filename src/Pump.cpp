// 
// ok
// 

#if 1

#include "Pump.h"


int Pump::cal_pump(int amount, int pump_num) 
{
	//�̰� �迭�Ⱦ��� �� 600���� ���൵ �ɰͰ���
	int pump_ratio[9] = { 600,600,600,600,600,600,600,600,600 }; // ���� �󸶳� �� ��������?
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
	//800,600**1
	//800,600**2
	//800,600**3
	//800,600**4
	//1500**********5�������� �� �ȳ�������_�ٷ� ����
	//�ڸ��� ���� �𸥴�6
	//2500**********���̴ٵ� �� �ȳ�������_�ٷ� ����
	
	//ó�� ����
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
	//15ml�� ����
	start_pump(pump_num);
	delay(cal_pump(amount, pump_num));//��ȯ �ð� �Է�
	stop_pump(pump_num);
}

#endif