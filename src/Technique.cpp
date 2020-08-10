// 
// ok
// 

#if 1

#include "Technique.h"


// ����:
void Technique::stir(int a_glass) 
{
	// �̵�: ������ �ؾ���
	Plate p;
	p.moveto(3015, 1800);
	p.move(-1050, 1);

	Actuator a(42, 43); // �ν��Ͻ� ����; ��ǰ�� �������� �� ��ȣ

	int actuator_time = 0;
	
	//�� ������ ���� ���� �ٸ���
	//�����ͺ��� 1,2,3,4
	switch (a_glass) {
	case 1:
		//�����ش�
		break;
	case 2:
		actuator_time = 8000;  break;
	case 3:
		actuator_time = 1500;  break;
	case 4:
		actuator_time = 2000;  break;
	}

	a.down();
	delay(actuator_time);
	a.idle();
	delay(1500);
	
	// ���� ON
	pinMode(48, OUTPUT);  
	pinMode(49, OUTPUT);

	digitalWrite(48, HIGH);
	digitalWrite(49, LOW);
	// ���� �ӵ� ���� (������ �� ��)
	//pinMode(32, OUTPUT);  analogWrite(32, 150);
	delay(3000); // ���� �ð� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	digitalWrite(30, HIGH);  digitalWrite(31, HIGH); // ���� ����
	delay(1500); // �� ���� ��ٸ��� �ð� @@@@@@@@@@@@@@@@@@@@@
	a.up();
	delay(actuator_time + 1000);
	a.idle();

	// ����ڿ��� ����
	p.moveto(640, 0);
	p.move_to_initial_position();
}


// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
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
	case TechniqueMethod::STIR:
		stir(glass);
	}

}


void Technique::add_ice(int a_glass)  // ������ �ؾ���
{
	Servo servo; // ���� �ν��Ͻ� ����
	servo.attach(10); // �� ��ȣ ����
	const int INIT_ANGLE = 175;
	const int FULL_ANGLE = 95;

	// �� ������ ���� ���� �� ���� �̸� ����, 1.0 = full�� �� ��
	double ice_amount_arr[4] = { 0.5, 1, 1.5 , 2 }; // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	double ice_amount = ice_amount_arr[a_glass - 1];

	// ���� �翡�� �󸶳� �ݺ����� ��� (ice_amount �ø�)
	int num = 1 + (int)ice_amount;

	// ice_amount �� ���� �ǽ��� �պ�� �ݺ�
	for (int i = 0; i < num; i++)
	{
		// ���� ��ǥ ����; ice_amount �� ���� �޶���
		int des_angle = 0;
		if ((int)ice_amount / 1) des_angle = FULL_ANGLE;
		else des_angle = (int)(FULL_ANGLE * ice_amount);

			// INIT_ANGLE -> des_angle �� ���� ������ �����ϴ� �ڵ�
			for (int j = INIT_ANGLE; j <= des_angle; j--) {
				servo.write(j);
				delay(15); // �ö� �� ������ �ӵ�
			}

		delay(1500); // �ǽ����� �ö���� (������ �о��) ��� ������ �ð�

		// des_angle -> INIT_ANGLE �� ���� ������ �����ϴ� �ڵ�
		for (int j = des_angle; j >= INIT_ANGLE; j++) {
			servo.write(j);
			delay(10); // ������ �� ������ �ӵ�
		}

		delay(2500); // �ǽ����� �������� (������ ä���) ��� ������ �ð�
		ice_amount--;
	}

} // end of for(num)



#endif