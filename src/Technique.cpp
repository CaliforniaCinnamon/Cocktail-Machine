// 
// ok
// 

#include "Technique.h"

extern Led* ledstrip1;
extern Led* ledstrip2;
extern Led* ledpanel;


// ����:
void Technique::stir() 
{
	// LED����
	int purple[3] = { 137, 119, 173 };
	ledstrip1->color(purple);
	ledstrip2->color(purple);
	ledpanel->random_color();

	// OLED ǥ��
	char* msg = "STIRRING...";
	Oled oled;
	oled.display_cocktail(msg);

	// �̵�: ������ �ؾ���
	Plate p;
	p.move_to(1, 2);
	p.move_to(3, 4);
	p.move_to(5, 6);

	// ��ǰ�� �۵�
	Actuator a(21, 22); // ��ǰ�� �������� �� ��ȣ
	a.down();
	
	pinMode(30, OUTPUT); // DC���� ��� ��
	analogWrite(30, 200); // 0~255 �ӵ����� ���� 12V���� 5V�ص� ����

	a.up();
	delay(5000); // �� �ö󰡱���� ��ٷ�
	a.idle();

	// ����ڿ��� ����
	p.move_to(10, 10);
}


// ����: LED ����� OLED ǥ�� ���� �ʿ�
void Technique::build() 
{
	// LED����
	int purple[3] = { 137, 119, 173 };
	ledstrip1->color(purple);
	ledstrip2->color(purple);
	ledpanel->random_color();
	
	// OLED ǥ��
	char* msg = "BUILDING...";
	Oled oled;
	oled.display_cocktail(msg);

	// ���� �� �ٸ� �ൿ ���� ������ ��ġ (final_pos)�� �̵�
	Plate p;
	p.move_to(10,10);// ����ڿ��� �ǳ� �� ������ ��ǥ
}

void Technique::f(TechniqueMethod method) {

	switch (method) {
	case TechniqueMethod::BUILD:
		build();
	case TechniqueMethod::STIR:
		stir();
	}

}

