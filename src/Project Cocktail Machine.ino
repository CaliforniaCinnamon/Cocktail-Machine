/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/



// ========= user-installed headers ==========

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


#define _TECHNIQUE_h
#define _PLATE_h
#define _OPERATION_h
#define _OLED_h
#define _MATERIAL_h
#define _LED_h
#define _COCKTAIL_h
#define _PUMP_h

// ============ global pointers ==============
Led* p_ledstrip1;  Led* p_ledstrip2;  Led* p_ledpanel;
Pump* pump_arr[7];
DispenserMaterial* disp_mtrl_arr[12];
PumpMaterial* pump_mtrl_arr[7];
Cocktail* cocktail_arr[18];


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
}


void loop() {
  while () { // 조건 추가해야함 (flag?)
	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_waiting(); // 함수 필요

	// LED 레인보우를 동시에 표현하기 위한 코드
	int time_marker = millis();
	p_ledstrip1->random(time_marker);
	p_ledstrip2->random(time_marker + 0);
	p_ledpanel->random(time_marker + 0);

	ctrl.bluetooth_connect();

	// 결과에 따라 나뉘어야 할 것 같은데..?
	/* pseudo code:
	아무 일도 없음 - 아무 실행도 하지 않고 그냥 계속 루프 반복
	제대로 된 값 입력 - 칵테일 인스턴스를 만들어서 넘겨줌 (어떻게?)
	종료하라는 명령 - 종료하는 함수를 실행함
	무효한 값 입력 - 값이 올바르지 않다고 알리고 다시 루프 반복
	*/

	} // end of while

  /* While문 벗어나고 pseudo code:
  Led 스트립 보라색으로 바꿈
  make_cocktail(ct);
  */
}



// =============== user-defined functions =================