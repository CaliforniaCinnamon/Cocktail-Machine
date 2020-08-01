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
}


void Oled::display_complete() {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	idisplay.setCursor(30, 30);
	idisplay.println("Complete!");
	idisplay.display();
}


// ���ڷ� 5(full) ~ 30(empty) �� ����
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
	this->display_right(msg);
	idisplay.display();
}

//Ĭ���� �̸� ���(�̸� �� �Ŵ� ���� �������� �ٹٲ�)
void Oled::display_right(char* msg) {
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
}

void Oled::clear() {
	idisplay.clearDisplay();
	idisplay.display();
}

void Oled::display_center(char* msg) {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	char* result = strtok(msg, " ");
	//i �ʱ� ���̶� ������ ���� �ʿ�
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(30, i); // display right �Լ����� ���⸸ �ٲ�
		idisplay.println(result);
		result = strtok(NULL, " ");
		i += 10;
	}
	idisplay.display();
}

void Oled::show() {
	idisplay.display();
}


void Oled::display_progress(int now, int amount, char* ct_name)
{
	// ���� ���� �� now�� ��ü �� amount ������ ���� �����ϸ�
	int how_much = (0 - 25) * now / amount + 30;
	
	// display_process�� ����; 5 (full) ~ 30 (empty)
	this->display_process(how_much);

	// ���൵ �׸� ���� Ĭ���� �̸��� ǥ���� �ش�

	this->display_right(ct_name);

}

// �Լ� �������̵�
void Oled::display_progress(int now, int amount, String ct_name)
{
	char* name;
	ct_name.toCharArray(name, ct_name.length() + 1);
	this->display_progress(now, amount, name);
}

#endif