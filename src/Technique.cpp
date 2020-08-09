// 
// ok
// 

#if 1

#include "Technique.h"


// ����:
void Technique::stir() 
{
	// �̵�: ������ �ؾ���
	Plate p;
	p.moveto(3015, 1800);
	p.move(-1050, 1);

	// ��ǰ�� �۵�
	Actuator a(24, 25); // ��ǰ�� �������� �� ��ȣ
	
	//�� ������ ���� ���� �ٸ���
	//�����ͺ��� 1,2,3,4
	switch (glass) {
	case 1:
		//�����ش�
		break;
	case 2:
		a.down();
		delay(8000);//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		a.idle();
		break;
	case 3:
		a.down();
		delay(1500);//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		a.idle();
		break;
	case 4:
		a.down();
		delay(2000);//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		a.idle();
		break;
	}
	
	// ���� ON
	pinMode(30, OUTPUT);  digitalWrite(30, HIGH);
	pinMode(31, OUTPUT);  digitalWrite(31, LOW);
	// ���� �ӵ� ���� (������ �� ��)
	//pinMode(32, OUTPUT);  analogWrite(32, 150);
	delay(3000); // ���� �ð� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	digitalWrite(30, HIGH);  digitalWrite(31, HIGH); // ���� ����
	delay(1000); // �� ���� ��ٸ��� �ð� @@@@@@@@@@@@@@@@@@@@@
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


void Technique::add_ice(int a_glass)  // ������ �ؾ���
{
	Servo servo; // ���� �ν��Ͻ� ����
	servo.attach(10); // �� ��ȣ ����
	const int SERVO_DELAY = 20; // ���������� ������ (�ӵ� ����) @@@@@@@@@@@@@@@@
	const int INIT_ANGLE = 0; // �ǽ����� ���������� �� ���� ���� @@@@@@@@@@@@@@@
	const int FULL_ANGLE = 90; // �ǽ����� ������ �ö����� �� ���� ���� @@@@@@@

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
			for (int j = INIT_ANGLE; j <= des_angle; j++) {
				servo.write(j);
				delay(SERVO_DELAY);
			}

		delay(1000); // �ǽ����� �ö���� (������ �о��) ��� ������ �ð� @@@@@@@@

		// des_angle -> INIT_ANGLE �� ���� ������ �����ϴ� �ڵ�
		for (int j = des_angle; j >= INIT_ANGLE; j++) {
			servo.write(j);
			delay(SERVO_DELAY);
		}

		delay(1000); // �ǽ����� �������� (������ ä���) ��� ������ �ð� @@@@@@@@
		ice_amount--;
	}

} // end of for(num)



#endif