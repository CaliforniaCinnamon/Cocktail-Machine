// Oled.h
// ����: Oled �ν��Ͻ��� ���������� �������� �� ��

#if 1
#pragma once

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
	void display_process(int i);

public:
	Oled();
	void display_bluetooth();
	void display_complete();
	void clear();
	void display_progress(int now, int amount, char* ct_name);
	void display_progress(int now, int amount, String ct_name);
	void display_right(char* msg);
	void display_center(char* msg);
	void show();
};

#endif


/*
���۷��� ��ũ
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library
*/