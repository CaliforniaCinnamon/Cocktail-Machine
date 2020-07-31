/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/



// ========= user-installed headers ==========
// (이것들 클래스의 헤더로 옮겨야함)

#include <SoftwareSerial.h>
#include <Stepper.h>

#include <splash.h>
#include <Adafruit_SSD1306.h>

#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_MonoOLED.h>
#include <Adafruit_GFX.h>


// ========= user-defined headers =========

#include "Operation.h"
#include "Pump.h"
#include "Led.h"
#include "Pump.h"


// ============ global pointers ==============
Led* p_ledstrip1;  Led* p_ledstrip2;  Led* p_ledpanel;
Pump* pump_arr[9];
DispenserMaterial* disp_mtrl_arr[12];
PumpMaterial* pump_mtrl_arr[9];
Cocktail* cocktail_arr[17];


// ============ global variables ============
Operation ctrl;


// ===================== setup & loop =====================
void setup() {
	Serial.begin(9600);
	ctrl.preset_led_instances();
	ctrl.preset_pump_instances();
	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();

	Plate p;
	p.move_to_initial_position(); // 혹시 모르니 처음 포지션으로 가

	Pump pump1(23, 24); //****************************************************핀넘버 설정필요
	Pump pump2(25, 26); 
	Pump pump3(27, 28);
	Pump pump4(29, 30);
	Pump pump5(31, 32);
	Pump pump6(33, 34);
	Pump pump7(35, 36);
	Pump pump8(35, 36);
	Pump pump9(35, 36);
	pump1.stop_pump();
	pump2.stop_pump();
	pump3.stop_pump();
	pump4.stop_pump();
	pump5.stop_pump();
	pump6.stop_pump();
	pump7.stop_pump();
	pump8.stop_pump();
	pump9.stop_pump();

	// 액츄에이터 초기 위치로 가!
	Actuator a(30, 31);
	a.down();
	delay(6000);
	a.up();
	delay(2300);
	a.idle();

}


void loop() {
	Operation ctrl;
	int flag = 1;  // 1이면 명령 기다림, 0이면 명령 탈출
	int res_index = -1;

	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_center("trame");

	while (flag) { // flag 1: 명령 기다림 | flag 0: 명령 받아 while 탈출
	// LED 레인보우를 동시에 표현하기 위한 코드
		int time_marker = millis();
		p_ledstrip1->random_color(time_marker);
		p_ledstrip2->random_color(time_marker + 0);
		p_ledpanel->random_color(time_marker + 0);

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
	} // end of while

	// LED 스트립 보라색으로 바꿈
	int purple[3] = { 121,0,214 }; // 보라색 rgb
	p_ledstrip1->color(purple);
	p_ledstrip2->color(purple);

	// 칵테일 만들기
	ctrl.make_cocktail(res_index);



}


// =============== user-defined functions =================