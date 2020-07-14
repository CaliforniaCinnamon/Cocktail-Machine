// 
// ����Ʈ �� Ŭ�������� ���� �ٲ�, ������ �굵 ���� �ٲ����.
// 

#include "Operation.h"

vector<Cocktail> Operation::preset_cocktail()
{
	vector<Cocktail> lists;
	map<DispenserMaterial, double> disp_temp;
	map<PumpMaterial, double> pump_temp;


	// ���漭 ��� �Ʒ��� �߰��ϱ�;
	DispenserMaterial vodka("vodka", 30, 30, 750, 50, 50, 200);

	// ���� ��� �Ʒ��� �߰��ϱ�;
	PumpMaterial orange_juice("orange_juice", 500, 30, 450, 230, 120, 0);

	// Ĭ���� �ν��Ͻ� ����� (4�ٴ���); 
	// (�ٵ� �ȿ��ִ� �������� ����ǳ�?) - ???? (�׽�Ʈ �غ��� �ȵǸ� �����ͷ� �ؾߵ� �Ф�)
	// ���� enum���� ��ȣ �����ؼ� �����Ϳ��� ���°� �?
	disp_temp = { {vodka, 70}, };
	pump_temp = { {orange_juice, 50}, };
	Cocktail skrew_driver("skrew_driver", TechniqueMethod::BUILD, disp_temp, pump_temp);
	lists.push_back(skrew_driver);


	return lists;
}



// ���� ������ �Լ�; ok
array<Pump, 5> Operation::preset_pumps()
{
	array<Pump, 5> temp;

	// �� ������ �������� �Է��� �� ��.
	temp[0] = Pump(1, 2);
	temp[1] = Pump(3, 4);
	temp[2] = Pump(5, 6);
	temp[3] = Pump(7, 8);
	temp[4] = Pump(9, 10);

	return temp;
}


// LED STRIP ������ �Լ�;
void Operation::preset_ledstrip()
{

}

// OLED ������ �Լ�
void Operation::preset_oled()
{

}


// �Լ� �������� �����ұ�...
int Operation::make_cocktail(Cocktail ct)
{
	// creating temp instances
	// ��׵��� ��� ó���ұ�? 
	// �׳� �ν��Ͻ� �����ؼ� ���°Ÿ� �����µ� �ʿ� ���ڴµ�...
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
