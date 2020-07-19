// 
// ���� �ʿ�
// 

#include "Oled.h"
Oled::Oled() {
	//idisplay(4);
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void Oled::display_bluetooth() {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(30, 27);
	idisplay.println("Bluetooth");
	idisplay.setCursor(20, 35);
	idisplay.println("is connected");
	idisplay.display();
	delay(2000);
}


void Oled::display_complete() {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(30, 30);
	idisplay.println("Complete!");
	idisplay.display();
	delay(2000);
}

//�̰� ���� �ȿ��� for�� �ݺ���Ű�� �ȵǴ��� �� �ȵǴ°���
//�׷��� ��¿ �� ���� ���� ���ڷ� �ް� main�Լ����� for �� �����ϱ� ��
void Oled::display_process(int i) {
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.drawLine(i, d1, d2, d1, WHITE);
	idisplay.display();
	delay(2000);
	idisplay.clearDisplay();
	delay(2000);
}

//Ĭ���� �̸� ���(�̸� �� �Ŵ� ���� �������� �ٹٲ�)
void Oled::display_cocktail(char*msg) {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	char* result = strtok(msg, " ");
	//i �ʱ� ���̶� ������ ���� �ʿ�
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(60, i);
		idisplay.println("%s", result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
	delay(2000);
}

void Oled::clear() {
	idisplay.clearDisplay();
}

void Oled::show() {
	idisplay.display();
}

/*
void Oled::temp() {
  idisplay.drawPixel(5, 5, 1);
  idisplay.drawPixel(10, 10, 1);
  idisplay.drawCircle(32, 32, 5, 1);
  idisplay.drawChar(20, 3, 'a', 1, 1, 1);
  idisplay.drawChar(26, 3, 'b', 1, 1, 1);
}*/


