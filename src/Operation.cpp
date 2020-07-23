// 
// ����Ʈ �� Ŭ�������� ���� �ٲ�, ������ �굵 ���� �ٲ����.
// 

#if 0

#include "Material.h"
#include "Operation.h"
#include <SoftwareSerial.h>


// ******************** main�� ���� ������ �������� ******************
extern Led * p_ledstrip1;  extern Led* p_ledstrip2;
extern Led* p_ledpanel;
extern Pump* pump_arr[7];

extern DispenserMaterial* disp_mtrl_arr[12];
extern PumpMaterial* pump_mtrl_arr[7];
extern Cocktail* cocktail_arr[18];


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

	pump_arr[0] = (Pump*)malloc(sizeof(pump1));
	pump_arr[1] = (Pump*)malloc(sizeof(pump2));
	pump_arr[2] = (Pump*)malloc(sizeof(pump3));
	pump_arr[3] = (Pump*)malloc(sizeof(pump4));
	pump_arr[4] = (Pump*)malloc(sizeof(pump5));
	pump_arr[5] = (Pump*)malloc(sizeof(pump6));
	pump_arr[6] = (Pump*)malloc(sizeof(pump7));

	*(pump_arr[0]) = pump1;
	*(pump_arr[1]) = pump2;
	*(pump_arr[2]) = pump3;
	*(pump_arr[3]) = pump4;
	*(pump_arr[4]) = pump5;
	*(pump_arr[5]) = pump6;
	*(pump_arr[6]) = pump7;
}

// ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
void Operation::preset_dispenser_materials()
{
	//dispenser_material_instance ����
	//DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	DispenserMaterial dispmaterial_instance1("Vodka", 0, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance2("Jean", 1, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance3("WhiteRum", 2, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance4("Tequila", 3, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance5("Cuentro", 4, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance6("Smynov", 5, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance7("GreenMelon", 6, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance8("Peach", 7, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance9("BlueCurasso", 8, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance10("Cassis", 9, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance11("Mohito", 10, 750, 200, 200, 200);
	DispenserMaterial dispmaterial_instance12("JackDaniel", 11, 750, 200, 200, 200);

	disp_mtrl_arr[0] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance1));
	disp_mtrl_arr[1] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance2));
	disp_mtrl_arr[2] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance3));
	disp_mtrl_arr[3] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance4));
	disp_mtrl_arr[4] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance5));
	disp_mtrl_arr[5] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance6));
	disp_mtrl_arr[6] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance7));
	disp_mtrl_arr[7] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance8));
	disp_mtrl_arr[8] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance9));
	disp_mtrl_arr[9] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance10));
	disp_mtrl_arr[10] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance11));
	disp_mtrl_arr[11] = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance12));

	*(disp_mtrl_arr[0]) = dispmaterial_instance1;
	*(disp_mtrl_arr[1]) = dispmaterial_instance2;
	*(disp_mtrl_arr[2]) = dispmaterial_instance3;
	*(disp_mtrl_arr[3]) = dispmaterial_instance4;
	*(disp_mtrl_arr[4]) = dispmaterial_instance5;
	*(disp_mtrl_arr[5]) = dispmaterial_instance6;
	*(disp_mtrl_arr[6]) = dispmaterial_instance7;
	*(disp_mtrl_arr[7]) = dispmaterial_instance8;
	*(disp_mtrl_arr[8]) = dispmaterial_instance9;
	*(disp_mtrl_arr[9]) = dispmaterial_instance10;
	*(disp_mtrl_arr[10]) = dispmaterial_instance11;
	*(disp_mtrl_arr[11]) = dispmaterial_instance12;

}

void Operation::preset_pump_materials()
{
	//pump_material_instance ����
	//PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	PumpMaterial pumpmaterial_instance1("Rasp", 0, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance2("Lemon", 1, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance3("Lime", 2, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance4("Sweet", 3, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance5("Orange", 4, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance6("Grp", 5, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance7("Tonic", 6, 750, 200, 200, 200);

	pump_mtrl_arr[0] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance1));
	pump_mtrl_arr[1] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance2));
	pump_mtrl_arr[2] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance3));
	pump_mtrl_arr[3] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance4));
	pump_mtrl_arr[4] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance5));
	pump_mtrl_arr[5] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance6));
	pump_mtrl_arr[6] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance7));

	*(pump_mtrl_arr[0]) = pumpmaterial_instance1;
	*(pump_mtrl_arr[1]) = pumpmaterial_instance2;
	*(pump_mtrl_arr[2]) = pumpmaterial_instance3;
	*(pump_mtrl_arr[3]) = pumpmaterial_instance4;
	*(pump_mtrl_arr[4]) = pumpmaterial_instance5;
	*(pump_mtrl_arr[5]) = pumpmaterial_instance6;
	*(pump_mtrl_arr[6]) = pumpmaterial_instance7;

}

void Operation::preset_cocktail_recipes()
{
	//cocktail_instance ����
	// �̸��� "Martini" �̷��� �ް�, �迭�� �ּҷ� ����. ����� BUILD STIR �̷��� ���ָ� ��.
	//Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],   TechniqueMethod a_method, int a_r, int a_g, int a_b);
	int disp_mtrl1[12] = { 0,0,45,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl1[7] = {0,0,20,0,0,0,0};
	Cocktail cocktail_instance1("Daiquiri", disp_mtrl1, pump_mtrl1, BUILD, 50, 1, 5);

	int disp_mtrl2[12] = {15,15,15,15,15,0,0,0,0,0,0,0};
	int pump_mtrl2[7] = {0,30,0,0,0,0,0};
	Cocktail cocktail_instance2("Longisland", disp_mtrl2, pump_mtrl2, BUILD, 50, 1, 5);

	int disp_mtrl3[12] = {0,0,30,0,0,0,0,0,0,0,0,0};
	int pump_mtrl3[7] = {15,0,15,0,0,0,0};
	Cocktail cocktail_instance3("Bacardi", disp_mtrl3, pump_mtrl3, BUILD, 50, 1, 5);

	int disp_mtrl4[12] = {30,0,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl4[7] = {60,0,0,0,0,15,0};
	Cocktail cocktail_instance4("ShiBreeze", disp_mtrl4, pump_mtrl4, BUILD, 50, 1, 5);

	int disp_mtrl5[12] = {0,0,0,0,0,45,0,0,0,0,0,0,0};
	int pump_mtrl5[7] = {0,0,0,};
	Cocktail cocktail_instance5("AppMartini", disp_mtrl5, pump_mtrl5, BUILD, 50, 1, 5);

	int disp_mtrl6[12] = {};
	int pump_mtrl6[7] = {};
	Cocktail cocktail_instance6("Cosmopolitan", disp_mtrl6, pump_mtrl6, BUILD, 50, 1, 5);

	int disp_mtrl7[12] = {};
	int pump_mtrl7[7] = {};
	Cocktail cocktail_instance7("TequilaSunrise", disp_mtrl7, pump_mtrl7, BUILD, 50, 1, 5);

	int disp_mtrl8[12] = {};
	int pump_mtrl8[7] = {};
	Cocktail cocktail_instance8("TomCollins", disp_mtrl8, pump_mtrl8, BUILD, 50, 1, 5);

	int disp_mtrl9[12] = {};
	int pump_mtrl9[7] = {};
	Cocktail cocktail_instance9("MelonCooler", disp_mtrl9, pump_mtrl9, BUILD, 50, 1, 5);

	int disp_mtrl10[12] = {};
	int pump_mtrl10[7] = {};
	Cocktail cocktail_instance10("Mohito", disp_mtrl10, pump_mtrl10, BUILD, 50, 1, 5);

	int disp_mtrl11[12] = {};
	int pump_mtrl11[7] = {};
	Cocktail cocktail_instance11("SoltiDog", disp_mtrl11, pump_mtrl11, BUILD, 50, 1, 5);

	int disp_mtrl12[12] = {};
	int pump_mtrl12[7] = {};
	Cocktail cocktail_instance12("ScrewDriver", disp_mtrl12, pump_mtrl12, BUILD, 50, 1, 5);

	int disp_mtrl13[12] = {};
	int pump_mtrl13[7] = {};
	Cocktail cocktail_instance13("BlueHawaii", disp_mtrl13, pump_mtrl13, BUILD, 50, 1, 5);

	int disp_mtrl14[12] = {};
	int pump_mtrl14[7] = {};
	Cocktail cocktail_instance14("Junbuck", disp_mtrl14, pump_mtrl14, BUILD, 50, 1, 5);

	int disp_mtrl15[12] = {};
	int pump_mtrl15[7] = {};
	Cocktail cocktail_instance15("PitchCrush", disp_mtrl15, pump_mtrl15, BUILD, 50, 1, 5);

	int disp_mtrl16[12] = {};
	int pump_mtrl16[7] = {};
	Cocktail cocktail_instance16("BlueRomance", disp_mtrl16, pump_mtrl16, BUILD, 50, 1, 5);

	int disp_mtrl17[12] = {};
	int pump_mtrl17[7] = {};
	Cocktail cocktail_instance17("JackHoneymong", disp_mtrl17, pump_mtrl17, BUILD, 50, 1, 5);

	int disp_mtrl18[12] = {};
	int pump_mtrl18[7] = {};
	Cocktail cocktail_instance18("ElDiablo", disp_mtrl18, pump_mtrl18, BUILD, 50, 1, 5);


	cocktail_arr[0] = (Cocktail*)malloc(sizeof(cocktail_instance1));
	cocktail_arr[1] = (Cocktail*)malloc(sizeof(cocktail_instance2));
	cocktail_arr[2] = (Cocktail*)malloc(sizeof(cocktail_instance3));
	cocktail_arr[3] = (Cocktail*)malloc(sizeof(cocktail_instance4));
	cocktail_arr[4] = (Cocktail*)malloc(sizeof(cocktail_instance5));
	cocktail_arr[5] = (Cocktail*)malloc(sizeof(cocktail_instance6));
	cocktail_arr[6] = (Cocktail*)malloc(sizeof(cocktail_instance7));
	cocktail_arr[7] = (Cocktail*)malloc(sizeof(cocktail_instance8));
	cocktail_arr[8] = (Cocktail*)malloc(sizeof(cocktail_instance9));
	cocktail_arr[9] = (Cocktail*)malloc(sizeof(cocktail_instance10));
	cocktail_arr[10] = (Cocktail*)malloc(sizeof(cocktail_instance11));
	cocktail_arr[11] = (Cocktail*)malloc(sizeof(cocktail_instance12));
	cocktail_arr[12] = (Cocktail*)malloc(sizeof(cocktail_instance13));
	cocktail_arr[13] = (Cocktail*)malloc(sizeof(cocktail_instance14));
	cocktail_arr[14] = (Cocktail*)malloc(sizeof(cocktail_instance15));
	cocktail_arr[15] = (Cocktail*)malloc(sizeof(cocktail_instance16));
	cocktail_arr[16] = (Cocktail*)malloc(sizeof(cocktail_instance17));
	cocktail_arr[17] = (Cocktail*)malloc(sizeof(cocktail_instance18));


	*(cocktail_arr[0]) = cocktail_instance1;
	*(cocktail_arr[1]) = cocktail_instance2;
	*(cocktail_arr[2]) = cocktail_instance3;
	*(cocktail_arr[3]) = cocktail_instance4;
	*(cocktail_arr[4]) = cocktail_instance5;
	*(cocktail_arr[5]) = cocktail_instance6;
	*(cocktail_arr[6]) = cocktail_instance7;
	*(cocktail_arr[7]) = cocktail_instance8;
	*(cocktail_arr[8]) = cocktail_instance9;
	*(cocktail_arr[9]) = cocktail_instance10;
	*(cocktail_arr[10]) = cocktail_instance11;
	*(cocktail_arr[11]) = cocktail_instance12;
	*(cocktail_arr[12]) = cocktail_instance13;
	*(cocktail_arr[13]) = cocktail_instance14;
	*(cocktail_arr[14]) = cocktail_instance15;
	*(cocktail_arr[15]) = cocktail_instance16;
	*(cocktail_arr[16]) = cocktail_instance17;
	*(cocktail_arr[17]) = cocktail_instance18;
}



// ************************* �Ҹ��� �Լ� **************************
Operation::~Operation() // �������� �Ҵ����� �ּҵ��� ������ �ش�.
{
	free(p_ledstrip1);
	free(p_ledstrip2);
	free(p_ledpanel);

	for (int i = 0; i < 7; i++) free(pump_arr[i]);
	for (int i = 0; i < 12; i++) free(disp_mtrl_arr[i]);
	for (int i = 0; i < 8; i++) free(pump_mtrl_arr[i]);
	for (int i = 0; i < 18; i++) free(cocktail_arr[i]);
}

// ********************** �۵��� ���� �Լ��� *********************

int select_make_recipe(String message)
{
	// �켱 message �� ���� & �� �ִ��� �˻�, ������ 20�� ��ȯ

	 // �־��� ���� -> �� ������ �迭 ����
	int disp_mtrl_amount[12] = { 0, };
	int pump_mtrl_amount[7] = { 0, };

	int i = 1; // message�� �ε���

	while (message[i] != '&') {
		String index = "";
		String amount = "";

		while (message[i] != '%') { // index ���� �޾ƿ���
			index += message[i];
			i++;
		} // end of internal while, %�� ������ ��������

		while (message[i] != '%') { // amount ���� �޾ƿ���
			amount += message[i];
			i++;
		} // end of internal while, %�� ������ ��������

		// String �ڷ����� index�� amount�� int �ڷ������� �ٲ�
		int index_int = index.toInt();
		int amount_int = amount.toInt();

		// index�� 0~11�̸� disp mtrl, 12~18�̸� pump mtrl
		if (0 <= index_int && index_int <= 11) {
			disp_mtrl_amount[index_int] = amount_int;
		}
		else if (12 <= index_int && index_int <= 18) {
			pump_mtlr_amount[index_int] = amount_int;
		}

		// ������ �˻� �޼����� char�� �������Ƿ� message�� �ε��� �ϳ� ����
		i++;
	} // end of while: disp_mtrl_amount �� pump_mtrl_amount �迭 ���� �Ϸ�

	// Ĭ���� �ν��Ͻ� ����
	Cocktail my_cocktail("my_cocktail", disp_mtrl_amount, pump_mtrl_amount)

		// �����Ҵ� �� �ּ� ����
		cocktail_arr[19] = (Cocktail*)malloc(sizeof(my_cocktail));
	*(cocktail_arr[19]) = my_cocktail;

	// ����
	return 19;
}


int bluetooth_connect() {
	while (bluetooth.available()) {
		char ch = bluetooth.read();
		str.concat(ch);
	}
	Serial.println(str);
	
	//select_sample
	if (str.charAt(0) == '$') {
		String res = ""; int i = 1;
		while (str.charAt(i) != '$') {
			char ch = str.charAt(i);
			res.concat(ch);
			i++;
		}
		return (res.toInt());
	}

	//make_recipe
	else if (str.charAt(0) == '&') {
		return select_make_recipe(str);
	}

	else return 20;
}



// Ĭ������ ����� �Լ�
int Operation::make_cocktail(int result_index)
{
	// ��Ʈ���� ���� �ν��Ͻ� ����;
	// Led, Pump �ν��Ͻ��� ������ ������ ������ ���
	Oled oled;
	Coord coord;
	Plate plate;

	// ����ϱ� ���� Ĭ���� �������� �̸� �������ش�.
	int* disp_recipe = ct.get_disp_recipe(); // ���� 12�� �迭
	int* pump_recipe = ct.get_pump_recipe(); // ���� 7�� �迭
	String ct_name = ct.get_name();
	int* ct_color = ct.get_cocktail_color(); // ���� 3�� �迭
	TechniqueMethod method = ct.get_technique();

	// ����� ��, OLED�� Ĭ���� �̸��� ǥ���ϰ� Led�� Ĭ���� ���� �Һ��� ����
	oled.display_cocktail(ct_name);
	p_ledpanel->color(ct_color);
	delay(5000);

	// �ܷ� Ȯ���ϰ�, �ܷ� ������ OLED�� ǥ���ϰ� �Լ� ����
	for (int i = 0; i < 12; i++) { // disp material �ܷ�üũ
		if (disp_recipe[i]) { // Ĭ���Ͽ� Ư�� ��Ḧ ����ϴ��� �˻�
		   // (������(�䱸��) > ���漭�� �����ִ� ��) �̸� ������ ���ϹǷ�
			if (disp_recipe[i] > (disp_mtrl_arr[i])->get_amount()) {
				oled.display_lack_of_amount(); // �����ϴٰ� oled ���, �Լ� ���� �ʿ�
				return 0; // �ٷ� �Լ��� �������´�. �����ڵ� 0: �ܷ�����
			}
		}
	}

	for (int i = 0; i < 7; i++) { // pump material �ܷ�üũ
		if (pump_recipe[i]) { // Ĭ���Ͽ� Ư�� ��Ḧ ����ϴ��� �˻�
		   // (������(�䱸��) > ���漭�� �����ִ� ��) �̸� ������ ���ϹǷ�
			if (pump_recipe[i] > (pump_mtrl_arr[i])->get_amount()) {
				oled.display_lack_of_amount(); // �����ϴٰ� oled ���, �Լ� ���� �ʿ�
				return 0; // �ٷ� �Լ��� �������´�. �����ڵ� 0: �ܷ�����
			}
		}
	}

	// �ܷ� üũ ������ Ĭ���� ����� ����
	// ���漭�� ����ϴ� ������ ����
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			DispenserMaterial material = *(disp_mtrl_arr[i]);

			// OLED ǥ��
			oled.display_cocktail(ct_name);

			// Led ���� ��� ������ ������ �ٲٱ�
			p_ledpanel->color(material.get_rgb());
			delay(1000); // �� �ٲٰ� 1�ʵ��� ��ٷ�

			// ��ǥ �����ϰ�, plate �����̱�
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.move_to(coord);
			delay(2000);

			// ��ǥ�� �̵������� �������� �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			plate.push_dispenser(disp_recipe[i]);

			// �������Ͱ� �� ������ ��������, �ش� ����� �ܷ��� ��
			int remain = material.get_amount() - disp_recipe[i];
			material.set_amount(remain);
			delay(1000);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	// ���漭 ���� ������ ����ϴ� ��� ���
	for (int i = 0; i < 7; i++) {
		if (pump_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			PumpMaterial material = *(pump_mtrl_arr[i]);

			// OLED ǥ��
			oled.display_cocktail(ct_name);

			// Led ���� ��� ������ ������ �ٲٱ�
			p_ledpanel->color(material.get_rgb());
			delay(1000); // �� �ٲٰ� 1�ʵ��� ��ٷ�

			// ��ǥ �����ϰ�, plate �����̱�
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.move_to(coord);
			delay(2000);

			// ��ǥ�� �̵������� !����! �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			pump_arr[i]->work_pump(pump_recipe[i]);

			// ���� �۵��� �Ϸ��ϸ�, �ش� ����� �ܷ��� ��
			int remain = material.get_amount() - pump_recipe[i];
			material.set_amount(remain);
			delay(1000);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	delay(3000);

	// ���� ����� ���� �����ϱ�
	oled.display_technique(); // �Լ� ����� �ʿ�, �ش� ����� OLED�� ǥ��
	p_ledpanel->color(ct_color); // �ش� Ĭ������ ���� �� ǥ��
	// �Լ� ������ ���� �ν��Ͻ� ����, ������ �������� method�� ������ �� ��� ����
	Technique t;
	t.f(method);

	// Ĭ���� �ϼ�!!
	oled_instance.display_complete();    // OLED�� �Ϸ��ߴٰ� ǥ��
	plate_instance.move_to_initial_position();    // move to init pos

	return 1; // ���� �ڵ� 1: Ĭ���� �ϼ�
}


int Operation::emergency_stop()
{
	print("emergency stop!");
	exit;
	return 2; // ���� �ڵ� 2: ��� ����
}


#endif