// 
// ok
// 

#if 1

#include "Technique.h"


// 스터:
void Technique::stir(int a_glass)
{
	Oled oled;
	oled.display_center("stirring");
	Actuator a(42, 43); // 인스턴스 생성; 거품기 액츄에이터 핀 번호

	// 이동: 여러번 해야함
	Plate p;
	p.moveto(3065, 1800);
	a.down();
	p.move(-1050, 1); // 2.1 ~ 2.2 초

	int actuator_time = 0;

	//잔 종류에 따라 높이 다르게
	//낮은것부터 1,2,3,4
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

	// 모터 ON
	pinMode(48, OUTPUT);
	pinMode(49, OUTPUT);

	digitalWrite(48, HIGH);
	digitalWrite(49, LOW);
	// 모터 속도 조절 (지금은 안 씀)
	//pinMode(32, OUTPUT);  analogWrite(32, 150);
	delay(5000); // 젓는 시간 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	digitalWrite(48, HIGH);  digitalWrite(49, HIGH); // 모터 정지
	delay(100); // 다 젓고 기다리는 시간 @@@@@@@@@@@@@@@@@@@@@
	a.up();
	delay(actuator_time + 3100);
	a.idle();

	oled.display_center("delivering");

	p.move(1050, 1);
	p.moveto(2500, 1800);

	// 사용자에게 전달
	p.moveto(640, 0);
	p.move_to_initial_position();
}

// 빌드: LED 색깔과 OLED 표시 설정 필요
void Technique::build() 
{
	Oled oled;

	oled.display_center("delivering");

	Plate p;
	p.moveto(640, 0);
	p.move_to_initial_position();// 사용자에게 건네 줄 마지막 좌표

}

void Technique::f(Cocktail ct) 
{
	// 받은 칵테일 정보에서 주조 기법, 잔 종류 정보를 빼옴
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


void Technique::add_ice(int a_glass)  // 서보로 해야함
{
	Servo servo; // 서보 인스턴스 선언
	servo.attach(10); // 핀 번호 설정
	const int INIT_ANGLE = 140;
	const int FULL_ANGLE = 40;

	// 잔 종류에 따른 얼음 양 정보 미리 저장, 1.0 = full로 한 번
	double ice_amount_arr[4] = { 1,1,1,1 };
	double ice_amount = ice_amount_arr[a_glass - 1];

	// 얼음 양에서 얼마나 반복할지 계산 (ice_amount 올림)
	int num = (int)(ice_amount + 0.5);

	servo.write(INIT_ANGLE); // 각도 초기화  

	// ice_amount 에 따라 피스톤 왕복운동 반복
	for (int i = 0; i < num; i++)
	{
		// 서보 목표 각도; ice_amount 에 따라 달라짐
		int des_angle = 0;
		if ((int)ice_amount / 1) des_angle = FULL_ANGLE;
		else des_angle = (int)((FULL_ANGLE - INIT_ANGLE) * ice_amount + INIT_ANGLE);

		// INIT_ANGLE -> des_angle 로 서보 각도를 제어하는 코드
		for (int j = INIT_ANGLE; j >= des_angle; j--) {
			servo.write(j);
			delay(30); // 올라갈 때 딜레이 속도
		}

		delay(1000); // 피스톤이 올라오고 (얼음을 밀어내고) 잠시 딜레이 시간

		// des_angle -> INIT_ANGLE 로 서보 각도를 제어하는 코드
		for (int j = des_angle; j <= INIT_ANGLE; j++) {
			servo.write(j);
			delay(10); // 내려갈 때 딜레이 속도
		}

		delay(1500); // 피스톤이 내려가고 (얼음을 채우고) 잠시 딜레이 시간
		ice_amount--;
	}

} // end of for(num)



#endif