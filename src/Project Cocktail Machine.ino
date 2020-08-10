/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/


// ========= user-installed headers ==========


// ========= user-defined headers ============
#include "Operation.h"


// ============ global variables =============
Operation ctrl;

// ===================== setup & loop =====================
void setup() 
{
	Oled oled_instance;
	oled_instance.display_preparing();

	Serial.begin(9600);

	  Serial.println("\n\n= start debugging...");

	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();

	ctrl.initialize();
}


void loop() 
{
	//Serial.println("Loopstart");
	// LED 인스턴스 생성
	Led ledstrip1(55, 3);
	Led ledstrip2(55, 4);
	Led ledpanel(256, 2);

	int flag = 1;  // 1이면 명령 기다림, 0이면 명령 탈출
	int res_index = -1; // bluetooth_connect의 리턴 값

	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_center("Welcome!"); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	delay(2000); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	oled.display_center("waiting for inputs..."); //@@@@@@@@@@@@@@@@@@

	while (flag) { // flag 1: 명령 기다림 | flag 0: 명령 받아 while 탈출
	// LED 레인보우를 동시에 표현하기 위한 코드
		int time_marker = millis();
		ledstrip1.random_color(time_marker); // 무지개 말고 단색으로 하느게 편할 것 같긴 함 @@@@@
		ledstrip2.random_color(time_marker);
		ledpanel.random_color(time_marker);

		res_index = ctrl.bluetooth_connect();
		// res_index notation:
		// 0~15: 미리 정의해놓은 칵테일
		// 16: 시그니쳐
		// 17: 나만의 레시피 or 랜덤 레시피
		// 18: 에러 | -1: 응답없음
		if (res_index == 18) ctrl.emergency_stop();
		else if (res_index >= 0 && res_index <= 17) {
			flag = 0;
		}
		// 보통 명령 없을 때, millis() 차이는 몇초?

		Serial.println(res_index);

	} // end of while

	// LED 스트립 보라색으로 바꿈
	int purple[3] = { 121,0,214 }; // 보라색 rgb
	ledstrip1.color(purple);
	ledstrip2.color(purple);
	ledpanel.color(purple);

	// 칵테일 만들기
	ctrl.make_cocktail(res_index);
	

}


// =============== user-defined functions =================