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
	//�� ������ ���� ���� �ٸ���
	//�����ͺ��� 1,2,3,4,5
	//5->2000
	//

	// �̵�: ������ �ؾ���
	Plate p;
	p.moveto(3015, 1800);
	p.move(-1050, 1);

	// ��ǰ�� �۵�
	Actuator a(24, 25); // ��ǰ�� �������� �� ��ȣ
	a.down();
	delay(500); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	pinMode(30, OUTPUT); // DC���� ��� ��
	pinMode(31, OUTPUT);
	analogWrite(30, 200); // 0~255 �ӵ����� ���� 12V���� 5V�ص� ���� @@@@@@@@@@@@@@@@@@
	analogWrite(31, 100);

	a.up();
	delay(5000); // �� �ö󰡱���� ��ٷ� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	a.idle();

	// ����ڿ��� ����
	p.move_to_initial_position();
}


// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
	Plate p;
	p.move_to_initial_position();// ����ڿ��� �ǳ� �� ������ ��ǥ
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
	// ���� ����̹� �� ��ȣ ���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	const int PIN_MOTOR_1 = 50;
	const int PIN_MOTOR_2 = 52;

	pinMode(11, INPUT);  // ����1�� ���ܼ� ���� �� ��ȣ ���� �ʿ� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	pinMode(12, INPUT);  // ����2��

	pinMode(PIN_MOTOR_1, OUTPUT);
	pinMode(PIN_MOTOR_2, OUTPUT);

	// num Ƚ����ŭ ������ ����. (���� �� ����)

	for (int i = 0; i < num; i++) {
		digitalWrite(PIN_MOTOR_1, HIGH); // �ǽ��� �ö󰡱�
		digitalWrite(PIN_MOTOR_2, LOW);

		// �Ѳ��� �����ϸ� digitalRead�� 0�̵Ǿ� ��ȣ�� ��������
		while (digitalRead(11)) {} // ���� �ִ� ���� (1��)

		// �Ѳ��� �����ؼ� while�� ���������� (�Ѳ��� ������) �극��ũ �ɾ���
		digitalWrite(PIN_MOTOR_1, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);

		delay(1000);  //*************************************************

		digitalWrite(PIN_MOTOR_1, LOW); // �ǽ��� ��������
		digitalWrite(PIN_MOTOR_2, HIGH);

		// �Ѳ��� �����ϸ� digitalRead�� 0�̵Ǿ� ��ȣ�� ��������
		while (digitalRead(12)) {} // �Ʒ��� �ִ� ���� (2��)

		// �Ѳ��� �����ؼ� while�� ���������� (�Ѳ��� ������) �극��ũ �ɾ���
		digitalWrite(PIN_MOTOR_1, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);
	}
}


#endif