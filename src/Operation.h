// Operation.h

#ifndef _OPERATION_h
#define _OPERATION_h

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
	vector<Cocktail> preset_cocktail();
	// �����Ϸ��� �˾Ƽ� ���۷��� ������� ���شٱ淡 ���������� ���ͷ� ��.
	array<Pump, 5> preset_pumps(); // 5��
	void preset_ledstrip();
	void preset_oled();
	// �ٵ� �����ϰ� ���� �ϳ��� ���൵ �� ��?
	void bluetooth_connect();
	// ����� �Լ� (loop)
	int make_cocktail(Cocktail ct);
	int emergency_stop();
};



#endif

