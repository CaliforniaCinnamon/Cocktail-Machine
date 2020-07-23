/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/



// ========= user-installed headers ==========

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
	bluetooth.begin(9600);
	ctrl.preset_led_instances();
	ctrl.preset_pump_instances();
	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();
}


void loop() {
	int flag = 1; int res_index = -1;
  while (flag) { // 조건 추가해야함 (flag?)
	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_waiting(); // 함수 필요

	// LED 레인보우를 동시에 표현하기 위한 코드
	int time_marker = millis();
	p_ledstrip1->random(time_marker);
	p_ledstrip2->random(time_marker + 0);
	p_ledpanel->random(time_marker + 0);

	res_index = ctrl.bluetooth_connect();
	int bluetooth_connect() {
		while (bluetooth.available()) {
			char ch = bluetooth.read();
			str.concat(ch);
		}
		Serial.println(str);

		//select_sample
		if (str.charAt(0) == '$') {
			String res = ""; int i = 1;
			while (str.charAt(i) != '$') {
				char ch = str.charAt(i);
				res.concat(ch);
				i++;
			}
			return (res.toInt());
		}

		//make_recipe
		else if (str.charAt(0) == '&') {
			return select_make_recipe(str);
		}

		else return 20;
	}



	//제대로 된 값 입력
	if (res_index >= 0 && res_index <= 20) {
		int flag = 0;
	}
} // end of while

  /* While문 벗어나고 pseudo code:
  Led 스트립 보라색으로 바꿈
  make_cocktail(ct);
  */

  ctrl.make_cocktail(res_index);

}



// =============== user-defined functions =================