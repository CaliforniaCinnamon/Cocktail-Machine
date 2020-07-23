// Technique.h

#if 1
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Plate.h"
#include "Led.h"
#include "Oled.h"


//method���� numbering
enum class TechniqueMethod {
	BUILD,
	STIR,
};


class Technique {
private:
	void build();
	void stir();
	TechniqueMethod method;

public:
	void f(TechniqueMethod method);
	void set_technique(TechniqueMethod tm) { method = tm; }

};


#endif

