// 
// ����Ʈ �� Ŭ�������� ���� �ٲ�, ������ �굵 ���� �ٲ����.
// 

#include "Operation.h"
#include <SoftwareSerial.h>


// ******************** main�� ���� ������ �������� ******************
extern Led* p_ledstrip1;  extern Led* p_ledstrip2;  
extern Led* p_ledpanel;
extern Pump* p_pump1;  extern Pump* p_pump2;  
extern Pump* p_pump3;  extern Pump* p_pump4;
extern Pump* p_pump5;  extern Pump* p_pump6;  
extern Pump* p_pump7;



// *************************** ������ �Լ��� *************************
void Operation::preset_led_instances()
{
	Led ledstrip1(50, 31); // led ����, �ɳѹ�
	Led ledstrip2(50, 32);
	Led ledpanel(256, 33);

	p_ledstrip1 = (Led*)malloc(sizeof(ledstrip1));
	p_ledstrip2 = (Led*)malloc(sizeof(ledstrip2));
	p_ledpanel = (Led*)malloc(sizeof(ledpanel));

	*(p_ledstrip1) = ledstrip1;
	*(p_ledstrip2) = ledstrip2;
	*(p_ledpanel) = ledpanel;
}

void Operation::preset_pump_instances() 
{
	Pump pump1(23, 24); // ��A, ��B
	Pump pump2(25, 26);
	Pump pump3(27, 28);
	Pump pump4(29, 30);
	Pump pump5(31, 32);
	Pump pump6(33, 34);
	Pump pump7(35, 36);

	p_pump1 = (Pump*)malloc(sizeof(pump1));
	p_pump2 = (Pump*)malloc(sizeof(pump2));
	p_pump3 = (Pump*)malloc(sizeof(pump3));
	p_pump4 = (Pump*)malloc(sizeof(pump4));
	p_pump5 = (Pump*)malloc(sizeof(pump5));
	p_pump6 = (Pump*)malloc(sizeof(pump6));
	p_pump7 = (Pump*)malloc(sizeof(pump7));


	*(p_pump1) = pump1;
	*(p_pump2) = pump2;
	*(p_pump3) = pump3;
	*(p_pump4) = pump4;
	*(p_pump5) = pump5;
	*(p_pump6) = pump6;
	*(p_pump7) = pump7;
}

// ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
void Operation::preset_dispenser_materials() 
{

}

void Operation::preset_pump_materials()
{

}

void Operation::preset_cocktail_recipes()
{

}



// ************************* �Ҹ��� �Լ� **************************
Operation::~Operation() // �������� �Ҵ����� �ּҵ��� ������ �ش�.
{
	free(p_ledstrip1);
	free(p_ledstrip2);
	free(p_ledpanel);
	free(p_pump1);
	free(p_pump2);
	free(p_pump3);
	free(p_pump4);
	free(p_pump5);
	free(p_pump6);
	free(p_pump7);
}



// ********************** �۵��� ���� �Լ��� *********************
void Operation::bluetooth_connect()//preset_bluetooth()�� �ұ�
{
	if (blueToothSerial.available()) {
		char message = blueToothSerial.read();
		if (message <= '0' && message <= '15') {//���ÿ��� char������ �����ߵ�
			//OLED ���� ��� "Bluetooth is connected"
			delay(3000);
			//LED ��Ʈ�� on
			delay(3000);
		}
	}
}


// �Լ� �������� �����ұ�...-> �����ϴ°� �����Ŷ� �����ߴµ� �� �ָ��ϳ�..(�ν��Ͻ� �����Լ�/���漭+����/
int Operation::make_cocktail(Cocktail ct)
{
	// creating temp instances
	// ��׵��� ��� ó���ұ�? 
	// �׳� �ν��Ͻ� �����ؼ� ���°Ÿ� �����µ� �ʿ� ���ڴµ�...->led,oled ������ �Լ��� ȭ�� ���� �� �����ϽŰǰ���??
	Oled oled_instance;
	LedStrip led_instance;
	Coord coord_instance;
	Plate plate_instance;
	Pump pump_instance;


	// checking remains...


	// OLED display name of the cocktail
	string name = ct.get_name();
	oled_instance.display_character(name); // �Լ� �̸��� �ٲ� �� ����.


	/*
	�߰��� �� �� ���� ��ٸ��� �Լ� ���� �� ����!!
	*/
	// loop; num of alcohol; ���漭 ������ŭ �ݺ�...
	auto disp_recipe = ct.get_disp_recipe();
	for (auto it = disp_recipe.begin(); it != disp_recipe.end(); it++)
	{
		DispenserMaterial material = it->first;

		// OLED display alcohol
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // �Լ� �̸� �޶��� �� ����

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// move plate z-axis (push dispenser)
		plate_instance.push_dispenser(it->second);
	}


	// loop; num of non-alcohol material; ���漭 ������ŭ �ݺ�...
	auto pump_recipe = ct.get_pump_recipe();
	for (auto it = pump_recipe.begin(); it != pump_recipe.end(); it++)
	{
		PumpMaterial material = it->first;

		// OLED display non-alcohol material
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // �Լ� �̸� �޶��� �� ����

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// activate pump
		pump_instance.work_pump(it->second); // �̰� ���� �Լ� �̸� �޶��� �� ����
	}


	// ���� ����� ���� �����ϱ�
	Technique ct_technique;
	ct_technique.f(ct.get_craft_method());


	// move to init pos
	plate_instance.move_to_initial_position();

	// OLED display 'complete'
	oled_instance.display_character("complete!"); // �Ϸ� ���� �޶��� �� ����

	return 0;
}


int Operation::emergency_stop()
{
	print("emergency stop!");
	exit;
	return 0;
}
