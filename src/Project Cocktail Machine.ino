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
/*
Adafruit_NeoPixel iledpanel = Adafruit_NeoPixel(256, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel iledstrip1 = Adafruit_NeoPixel(55, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel iledstrip2 = Adafruit_NeoPixel(55, 4, NEO_GRB + NEO_KHZ800);*/

// ===================== setup & loop =====================
void setup() 
{
	//Oled oled_instance;
	//oled_instance.display_preparing();

	Serial.begin(9600);

	  Serial.println("\n\n= start debugging...");

	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();

	ctrl.initialize();
}


void loop() 
{
	/*
	// LED 인스턴스 생성
	iledpanel.begin();
	iledstrip1.begin();
	iledstrip2.begin();

	iledpanel.clear();
	iledpanel.setBrightness(20);
	iledpanel.show();

	iledstrip1.clear();
	iledstrip1.setBrightness(50);
	iledstrip1.show();

	iledstrip2.clear();
	iledstrip2.setBrightness(50);
	iledstrip2.show();*/


	int flag = 1;  // 1이면 명령 기다림, 0이면 명령 탈출
	int res_index = -1; // bluetooth_connect의 리턴 값

	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_center("Welcome!");
	delay(2000); 
	oled.display_center("waiting");
	
	/*
	for (int i = 0; i < 256; i++) {
		iledpanel.setPixelColor(i, 121, 0, 214);
	}
	iledpanel.show();
		
	for (int i = 0; i < 55; i++) {
		iledstrip1.setPixelColor(i, 121, 0, 214);
	}
	iledstrip1.show();

	for (int i = 0; i < 55; i++) {
		iledstrip2.setPixelColor(i, 121, 0, 214);
	}
	iledstrip2.show();*/

	while (flag) { // flag 1: 명령 기다림 | flag 0: 명령 받아 while 탈출
	// LED 레인보우를 동시에 표현하기 위한 코드
		int time_marker = millis();

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

	// 칵테일 만들기
	ctrl.make_cocktail(res_index);
	delay(2000);
	

}


// =============== user-defined functions =================