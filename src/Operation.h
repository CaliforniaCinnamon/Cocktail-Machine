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
	// bluetooth_connect �Լ��� �����
	int select_make_recipe(String message);

public:
	// ������ �Լ� (setup)
		// �ν��Ͻ� �¾��ϱ� (Led 3, Pump 7)
	void preset_led_instances();
	void preset_pump_instances();

		// ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
	void preset_dispenser_materials();
	void preset_pump_materials();
	void preset_cocktail_recipes();

	// �Ҹ��� �Լ�
	~Operation();

	// �۵� �Լ�
	int bluetooth_connect();
	int make_cocktail(int res_index);
	int emergency_stop();
};



#endif

