// Oled.h

#ifndef _OLED_h
#define _OLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class Oled {
private:
	Adafruit_SSD1306 idisplay; // �׷��� ��¿� �ν��Ͻ�
public:
	Oled();
	void display_character(const char* msg);
	void display_graphic(const uint8_t* graphic_data);
	void clear();
	void show();

	void temp();

};

#endif


/*
���۷��� ��ũ
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
*/
