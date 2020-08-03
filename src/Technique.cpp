// 
// ok
// 

#if 1

#include "Technique.h"

extern Led* ledstrip1;
extern Led* ledstrip2;
extern Led* ledpanel;


// 스터:
void Technique::stir() 
{
	// 이동: 여러번 해야함
	Plate p;
	p.move_to(1, 2);
	p.move_to(3, 4);
	p.move_to(5, 6);

	// 거품기 작동
	Actuator a(21, 22); // 거품기 액츄에이터 핀 번호
	a.down();
	
	pinMode(30, OUTPUT); // DC모터 출력 핀
	pinMode(31, OUTPUT);
	analogWrite(30, 200); // 0~255 속도조절 원래 12V지만 5V해도 ㄱㅊ
	analogWrite(31, 100);//********************확인해보고 둘이 조절

	a.up();
	delay(5000); // 다 올라가기까지 기다려
	a.idle();

	// 사용자에게 전달
	p.move_to(10, 10);
}


// 빌드: LED 색깔과 OLED 표시 설정 필요
void Technique::build() 
{
	// 딱히 별 다른 행동 없이 정해진 위치 (final_pos)로 이동
	Plate p;
	p.move_to(10,10);// 사용자에게 건네 줄 마지막 좌표
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
	// 모터 드라이버 핀 번호 설정
	const int PIN_MOTOR_1 = 50;
	const int PIN_MOTOR_2 = 52;

	pinMode(11, INPUT);  //***************** 적외선 센서 핀 번호 설정 필요

	pinMode(PIN_MOTOR_1, OUTPUT);
	pinMode(PIN_MOTOR_2, OUTPUT);

	// num 횟수만큼 얼음을 투하. (얼음 양 조절)

	for (int i = 0; i < num; i++) {
		digitalWrite(PIN_MOTOR_1, HIGH); // 모터 작동
		digitalWrite(PIN_MOTOR_2, LOW);

		// 작동하자마자 바로 닫힌 것으로 인식하여 종료할 수 있기 때문에 잠깐 딜레이를 걸어줌
		delay(100);

		// 뚜껑을 감지하면 digitalRead가 0이되어 신호를 빠져나옴
		while (digitalRead(11)) {}

		// 뚜껑을 감지해서 while을 빠져나오면 (뚜껑이 닫히면) 브레이크 걸어줌
		digitalWrite(PIN_MOTOR_2, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);
		delay(1000);
	}
}


#endif