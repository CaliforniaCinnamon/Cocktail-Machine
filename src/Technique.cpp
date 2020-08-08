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
	//잔 종류에 따라 높이 다르게
	//낮은것부터 1,2,3,4,5
	//5->2000
	//

	// 이동: 여러번 해야함
	Plate p;
	p.moveto(3015, 1800);
	p.move(-1050, 1);

	// 거품기 작동
	Actuator a(24, 25); // 거품기 액츄에이터 핀 번호
	a.down();
	delay(500); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	pinMode(30, OUTPUT); // DC모터 출력 핀
	pinMode(31, OUTPUT);
	analogWrite(30, 200); // 0~255 속도조절 원래 12V지만 5V해도 ㄱㅊ @@@@@@@@@@@@@@@@@@
	analogWrite(31, 100);

	a.up();
	delay(5000); // 다 올라가기까지 기다려 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	a.idle();

	// 사용자에게 전달
	p.move_to_initial_position();
}


// 빌드: LED 색깔과 OLED 표시 설정 필요
void Technique::build() 
{
	Plate p;
	p.move_to_initial_position();// 사용자에게 건네 줄 마지막 좌표
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
	// 모터 드라이버 핀 번호 설정 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	const int PIN_MOTOR_1 = 50;
	const int PIN_MOTOR_2 = 52;

	pinMode(11, INPUT);  // 센서1번 적외선 센서 핀 번호 설정 필요 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	pinMode(12, INPUT);  // 센서2번

	pinMode(PIN_MOTOR_1, OUTPUT);
	pinMode(PIN_MOTOR_2, OUTPUT);

	// num 횟수만큼 얼음을 투하. (얼음 양 조절)

	for (int i = 0; i < num; i++) {
		digitalWrite(PIN_MOTOR_1, HIGH); // 피스톤 올라가기
		digitalWrite(PIN_MOTOR_2, LOW);

		// 뚜껑을 감지하면 digitalRead가 0이되어 신호를 빠져나옴
		while (digitalRead(11)) {} // 위에 있는 센서 (1번)

		// 뚜껑을 감지해서 while을 빠져나오면 (뚜껑이 닫히면) 브레이크 걸어줌
		digitalWrite(PIN_MOTOR_1, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);

		delay(1000);  //*************************************************

		digitalWrite(PIN_MOTOR_1, LOW); // 피스톤 내려가기
		digitalWrite(PIN_MOTOR_2, HIGH);

		// 뚜껑을 감지하면 digitalRead가 0이되어 신호를 빠져나옴
		while (digitalRead(12)) {} // 아래에 있는 센서 (2번)

		// 뚜껑을 감지해서 while을 빠져나오면 (뚜껑이 열리면) 브레이크 걸어줌
		digitalWrite(PIN_MOTOR_1, HIGH);
		digitalWrite(PIN_MOTOR_2, HIGH);
	}
}


#endif