// Led.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>

class Led {
private:
	int numpixels;
	int brightness; //�׿��ȼ� ��� ���� 0(��ο�)-255(����)
	int PIN_LED;
	int user_delay;

	Adafruit_NeoPixel strip;

	void colorWipe(uint32_t c, uint8_t wait);
	uint32_t Wheel(byte WheelPos);
	void rainbow();
	void rainbowCycle();

public:
	Led(int a_numpixel, int a_pin);

	void set_delay(int d);
	void set_brightness(int x);
	void off_gradually();//���� �Լ�
	void off();
	void color(int* cock_color);//����� ���� ��Ÿ���� �Լ�
	void random_color(); //�� �Լ��� �ǳ� �� �Ʒ��� �� �Լ� �� �ϳ��� ����
	void temp();
};


#endif

