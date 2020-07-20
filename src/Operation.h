// Operation.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Plate.h"
#include "Cocktail.h"
#include "Technique.h"
#include "Pump.h"
#include <array>
#include <vector>


class Operation {
private:

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
	void bluetooth_connect();
	int make_cocktail(Cocktail ct);
	int emergency_stop();
};



#endif

