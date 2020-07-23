// Operation.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Material.h"
#include "Plate.h"
#include "Cocktail.h"
#include "Technique.h"
#include "Pump.h"
#include <SoftwareSerial.h>


class Operation {
private:
	// bluetooth_connect 함수에 내장됨
	int select_make_recipe(String message);

public:
	// 프리셋 함수 (setup)
		// 인스턴스 셋업하기 (Led 3, Pump 7)
	void preset_led_instances();
	void preset_pump_instances();

		// 정보 셋업하기 (재료들의 위치, 칵테일 레시피)
	void preset_dispenser_materials();
	void preset_pump_materials();
	void preset_cocktail_recipes();

	// 소멸자 함수
	~Operation();

	// 작동 함수
	int bluetooth_connect();
	int make_cocktail(int res_index);
	int emergency_stop();
};



#endif

