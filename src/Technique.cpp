// 
// ok
// 

#if 1

#include "Technique.h"


// ����:
void Technique::stir(int a_glass)
{
	Oled oled;
	oled.display_center("stirring");
	Actuator a(42, 43); // �ν��Ͻ� ����; ��ǰ�� �������� �� ��ȣ

	// �̵�: ������ �ؾ���
	Plate p;
	p.moveto(3065, 1800);
	a.down();
	p.move(-1050, 1); // 2.1 ~ 2.2 ��

	int actuator_time = 0;

	//�� ������ ���� ���� �ٸ���
	//�����ͺ��� 1,2,3,4
	switch (a_glass) {
	case 2:
		actuator_time = 8900;  break;
	case 3:
		actuator_time = 5900;  break;
	case 4:
		actuator_time = 2900;  break;
	}

	delay(actuator_time);
	a.idle();

	// ���� ON
	pinMode(48, OUTPUT);
	pinMode(49, OUTPUT);

	digitalWrite(48, HIGH);
	digitalWrite(49, LOW);
	// ���� �ӵ� ���� (������ �� ��)
	//pinMode(32, OUTPUT);  analogWrite(32, 150);
	delay(5000); // ���� �ð� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	digitalWrite(48, HIGH);  digitalWrite(49, HIGH); // ���� ����
	delay(100); // �� ���� ��ٸ��� �ð� @@@@@@@@@@@@@@@@@@@@@
	a.up();
	delay(actuator_time + 3100);
	a.idle();

	oled.display_center("delivering");

	p.move(1050, 1);
	p.moveto(2500, 1800);

	// ����ڿ��� ����
	p.moveto(640, 0);
	p.move_to_initial_position();
}

// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
	Oled oled;

	oled.display_center("delivering");

	Plate p;
	p.moveto(640, 0);
	p.move_to_initial_position();// ����ڿ��� �ǳ� �� ������ ��ǥ

}

void Technique::f(Cocktail ct) 
{
	// ���� Ĭ���� �������� ���� ���, �� ���� ������ ����
	TechniqueMethod method = ct.get_technique();
	int glass = ct.get_glass_info(); // 1~4

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
		break;
	case TechniqueMethod::STIR:
		stir(glass);
		break;
	}

}


void Technique::add_ice(int a_glass)  // ������ �ؾ���
{
	Servo servo; // ���� �ν��Ͻ� ����
	servo.attach(10); // �� ��ȣ ����
	const int INIT_ANGLE = 140;
	const int FULL_ANGLE = 40;

	// �� ������ ���� ���� �� ���� �̸� ����, 1.0 = full�� �� ��
	double ice_amount_arr[4] = { 1,1,1,1 };
	double ice_amount = ice_amount_arr[a_glass - 1];

	// ���� �翡�� �󸶳� �ݺ����� ��� (ice_amount �ø�)
	int num = (int)(ice_amount + 0.5);

	servo.write(INIT_ANGLE); // ���� �ʱ�ȭ  

	// ice_amount �� ���� �ǽ��� �պ�� �ݺ�
	for (int i = 0; i < num; i++)
	{
		// ���� ��ǥ ����; ice_amount �� ���� �޶���
		int des_angle = 0;
		if ((int)ice_amount / 1) des_angle = FULL_ANGLE;
		else des_angle = (int)((FULL_ANGLE - INIT_ANGLE) * ice_amount + INIT_ANGLE);

		// INIT_ANGLE -> des_angle �� ���� ������ �����ϴ� �ڵ�
		for (int j = INIT_ANGLE; j >= des_angle; j--) {
			servo.write(j);
			delay(30); // �ö� �� ������ �ӵ�
		}

		delay(1000); // �ǽ����� �ö���� (������ �о��) ��� ������ �ð�

		// des_angle -> INIT_ANGLE �� ���� ������ �����ϴ� �ڵ�
		for (int j = des_angle; j <= INIT_ANGLE; j++) {
			servo.write(j);
			delay(10); // ������ �� ������ �ӵ�
		}

		delay(1500); // �ǽ����� �������� (������ ä���) ��� ������ �ð�
		ice_amount--;
	}

} // end of for(num)



#endif