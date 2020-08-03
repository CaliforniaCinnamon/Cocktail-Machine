// 
// ok
// 

#if 1

#include "Technique.h"

extern Led* ledstrip1;
extern Led* ledstrip2;
extern Led* ledpanel;


// ����:
void Technique::stir() 
{
	// �̵�: ������ �ؾ���
	Plate p;
	p.move_to(1, 2);
	p.move_to(3, 4);
	p.move_to(5, 6);

	// ��ǰ�� �۵�
	Actuator a(21, 22); // ��ǰ�� �������� �� ��ȣ
	a.down();
	
	pinMode(30, OUTPUT); // DC���� ��� ��
	pinMode(31, OUTPUT);
	analogWrite(30, 200); // 0~255 �ӵ����� ���� 12V���� 5V�ص� ����
	analogWrite(31, 100);//********************Ȯ���غ��� ���� ����

	a.up();
	delay(5000); // �� �ö󰡱���� ��ٷ�
	a.idle();

	// ����ڿ��� ����
	p.move_to(10, 10);
}


// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
	// ���� �� �ٸ� �ൿ ���� ������ ��ġ (final_pos)�� �̵�
	Plate p;
	p.move_to(10,10);// ����ڿ��� �ǳ� �� ������ ��ǥ
}

void Technique::f(TechniqueMethod method) {

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
	case TechniqueMethod::STIR:
		stir();
	}

}


void Technique::add_ice(int num) 
{
	// ���� ����̹� �� ��ȣ ����
	const int PIN_MOTOR_1 = 50;
	const int PIN_MOTOR_2 = 52;

	pinMode(11, INPUT);  //***************** ���ܼ� ���� �� ��ȣ ���� �ʿ�

	pinMode(PIN_MOTOR_1, OUTPUT);
	pinMode(PIN_MOTOR_2, OUTPUT);

	// num Ƚ����ŭ ������ ����. (���� �� ����)

	for (int i = 0; i < num; i++) {
		digitalWrite(PIN_MOTOR_1, HIGH); // ���� �۵�
		digitalWrite(PIN_MOTOR_2, LOW);

		// �۵����ڸ��� �ٷ� ���� ������ �ν��Ͽ� ������ �� �ֱ� ������ ��� �����̸� �ɾ���
		delay(100);

		// �Ѳ��� �����ϸ� digitalRead�� 0�̵Ǿ� ��ȣ�� ��������
		while (digitalRead(11)) {}

		// �Ѳ��� �����ؼ� while�� ���������� (�Ѳ��� ������) �극��ũ �ɾ���
		digitalWrite(PIN_MOTOR_2, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);
		delay(1000);
	}
}


#endif