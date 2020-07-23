// 
// ���� �ʿ�
// 

#if 1

#include "Oled.h"
Oled::Oled() {
	//idisplay(4);
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	idisplay.clearDisplay();
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

/*�̰� ���� �ȿ��� for�� �ݺ���Ű�� �ȵǴ��� �� �ȵǴ°���
  �׷��� ��¿ �� ���� ���� ���ڷ� �ް� main�Լ����� for �� �����ϱ� ��
  �� �ϴ� ���� ��� ǥ������ �ٽ� ���ϴ°� ���ھ��! �Ф� ���� �򰥸��׿�*/
void Oled::display_process(int i) 
{
	// �� ���̾ƿ��� �׸��� �ڵ�
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);

	// �ܰ踦 ǥ���ϱ� ���� ���
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.fillTriangle(i, d1, d2, d1, 30, 35, WHITE);

	// �� ���� �߰��� �ڵ�. �̷��� ���� ����? ����� ����� �̸��� ���?
	char msg[] = "making cocktail...";
	this->display_cocktail(msg);
	idisplay.display();

	/* �ڵ��� �ǵ��� �𸣰ڴ�... �׽�Ʈ��?
	  �� ������ ���ߵ� ������ ǥ������ ��Ȯ�ϰ� ���ϱⰡ 1���� ��ǥ
	delay(2000);
	idisplay.clearDisplay();
	delay(2000);*/
}

//Ĭ���� �̸� ���(�̸� �� �Ŵ� ���� �������� �ٹٲ�)
void Oled::display_cocktail(char* msg) {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	char* result = strtok(msg, " ");
	//i �ʱ� ���̶� ������ ���� �ʿ�
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(60, i);
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
	delay(2000);
}

void Oled::clear() {
	idisplay.clearDisplay();
	idisplay.display();
}


#endif