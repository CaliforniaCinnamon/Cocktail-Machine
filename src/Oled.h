// Oled.h

#ifndef _OLED_h
#define _OLED_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

class Oled {
private:
	Adafruit_SSD1306 idisplay; // �׷��� ��¿� �ν��Ͻ�
public:
	Oled();
	void display_bluetooth();
	void display_complete();
	void display_process(int i);
	void clear();
	void display_cocktail(char* msg);
	void show();
	void temp();

};

#endif


/*
���۷��� ��ũ
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
*/