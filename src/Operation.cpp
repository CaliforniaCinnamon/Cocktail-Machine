// 
// ����Ʈ �� Ŭ�������� ���� �ٲ�, ������ �굵 ���� �ٲ����.
// 

#if 1


#include "Operation.h"

// ******************** main�� ���� ������ �������� ******************
extern Led * p_ledstrip1;  extern Led* p_ledstrip2;  extern Led* p_ledpanel;
extern Pump* pump_arr[9];

extern DispenserMaterial* disp_mtrl_arr[12];
extern PumpMaterial* pump_mtrl_arr[9];
extern Cocktail* cocktail_arr[18];


// *************************** ������ �Լ��� *************************
void Operation::preset_led_instances()
{
	Led ledstrip1(55, 3); // led ����, �ɳѹ�
	Led ledstrip2(55, 4);
	Led ledpanel(256, 2);

	p_ledstrip1 = (Led*)malloc(sizeof(ledstrip1));
	p_ledstrip2 = (Led*)malloc(sizeof(ledstrip2));
	p_ledpanel = (Led*)malloc(sizeof(ledpanel));

	*(p_ledstrip1) = ledstrip1;
	*(p_ledstrip2) = ledstrip2;
	*(p_ledpanel) = ledpanel;
}

void Operation::preset_pump_instances()
{
	Pump pump1(30); // ��A
	Pump pump2(31); //****************************************************�ɳѹ� �����ʿ�
	Pump pump3(32);
	Pump pump4(33);
	Pump pump5(34);
	Pump pump6(35);
	Pump pump7(36);
	Pump pump8(37);
	Pump pump9(38, 39);

	pump_arr[0] = (Pump*)malloc(sizeof(pump1));
	pump_arr[1] = (Pump*)malloc(sizeof(pump2));
	pump_arr[2] = (Pump*)malloc(sizeof(pump3));
	pump_arr[3] = (Pump*)malloc(sizeof(pump4));
	pump_arr[4] = (Pump*)malloc(sizeof(pump5));
	pump_arr[5] = (Pump*)malloc(sizeof(pump6));
	pump_arr[6] = (Pump*)malloc(sizeof(pump7));
	pump_arr[7] = (Pump*)malloc(sizeof(pump8));
	pump_arr[8] = (Pump*)malloc(sizeof(pump9));

	*(pump_arr[0]) = pump1;
	*(pump_arr[1]) = pump2;
	*(pump_arr[2]) = pump3;
	*(pump_arr[3]) = pump4;
	*(pump_arr[4]) = pump5;
	*(pump_arr[5]) = pump6;
	*(pump_arr[6]) = pump7;
	*(pump_arr[7]) = pump8;
	*(pump_arr[8]) = pump9;
}

// ���� �¾��ϱ� (������ ��ġ, Ĭ���� ������)
void Operation::preset_dispenser_materials()
{
	//dispenser_material_instance ����
	//DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	DispenserMaterial dispmaterial_instance1("Vodka", 0, 750, 250, 250, 250);
	DispenserMaterial dispmaterial_instance2("Jean", 1, 750, 180, 220, 220);
	DispenserMaterial dispmaterial_instance3("WhiteRum", 2, 750, 250, 250, 250);
	DispenserMaterial dispmaterial_instance4("Tequila", 3, 750, 240, 240, 95);
	DispenserMaterial dispmaterial_instance5("Cuentro", 4, 750, 210, 145, 45);
	DispenserMaterial dispmaterial_instance6("Smynov", 5, 750, 130, 225, 120);
	DispenserMaterial dispmaterial_instance7("Soju", 6, 360, 130, 225, 120);
	DispenserMaterial dispmaterial_instance8("Peach", 7, 750, 250, 160, 205);
	DispenserMaterial dispmaterial_instance9("BlueCurasso", 8, 750, 60, 60, 210);
	DispenserMaterial dispmaterial_instance10("Beer", 9, 500, 110, 65, 100);
	DispenserMaterial dispmaterial_instance11("Mohito", 10, 750, 130, 215, 125);
	DispenserMaterial dispmaterial_instance12("JackDaniel", 11, 750, 210, 140, 60);

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
	PumpMaterial pumpmaterial_instance1("Raspberry", 13, 750, 200, 50, 40);
	PumpMaterial pumpmaterial_instance2("Lemon", 14, 750, 255, 255, 10);
	PumpMaterial pumpmaterial_instance3("Lime", 15, 750, 120, 210, 100);
	PumpMaterial pumpmaterial_instance4("Sweet & Sour", 16, 750, 230, 230, 100);
	PumpMaterial pumpmaterial_instance5("Orange", 17, 750, 255, 130, 0);
	PumpMaterial pumpmaterial_instance6("Grapefruit juice", 18, 750, 255, 185, 115);
	PumpMaterial pumpmaterial_instance7("Tonic", 19, 750, 255, 255, 255);
	PumpMaterial pumpmaterial_instance8("Unknwon1", 20, 750, 128, 64, 64); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	PumpMaterial pumpmaterial_instance9("Unknwon2", 21, 750, 255, 255, 255); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	pump_mtrl_arr[0] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance1));
	pump_mtrl_arr[1] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance2));
	pump_mtrl_arr[2] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance3));
	pump_mtrl_arr[3] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance4));
	pump_mtrl_arr[4] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance5));
	pump_mtrl_arr[5] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance6));
	pump_mtrl_arr[6] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance7));
	pump_mtrl_arr[7] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance8));
	pump_mtrl_arr[8] = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance9));

	*(pump_mtrl_arr[0]) = pumpmaterial_instance1;
	*(pump_mtrl_arr[1]) = pumpmaterial_instance2;
	*(pump_mtrl_arr[2]) = pumpmaterial_instance3;
	*(pump_mtrl_arr[3]) = pumpmaterial_instance4;
	*(pump_mtrl_arr[4]) = pumpmaterial_instance5;
	*(pump_mtrl_arr[5]) = pumpmaterial_instance6;
	*(pump_mtrl_arr[6]) = pumpmaterial_instance7;
	*(pump_mtrl_arr[7]) = pumpmaterial_instance8;
	*(pump_mtrl_arr[8]) = pumpmaterial_instance9;

}

void Operation::preset_cocktail_recipes() // ���� ��� BUILD or STIR ���ϱ� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
	//cocktail_instance ����
	// �̸��� "Martini" �̷��� �ް�, �迭�� �ּҷ� ����. ����� BUILD STIR �̷��� ���ָ� ��.
	//Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],   TechniqueMethod a_method, int glass, int a_r, int a_g, int a_b);
	//glass�� ���� �ͺ��� 1,2,3,4
	int disp_mtrl1[12] = { 0,0,45,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl1[9] = {0,0,20,0,0,0,0,0,0};
	Cocktail cocktail_instance1("Daiquiri", disp_mtrl1, pump_mtrl1, TechniqueMethod::BUILD, 4, 200, 255, 150);

	int disp_mtrl2[12] = { 15,15,15,15,15,0,0,0,0,0,0,0 };
	int pump_mtrl2[9] = { 0,30,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance2("Longisland", disp_mtrl2, pump_mtrl2, TechniqueMethod::BUILD, 3, 115, 60, 60);

	int disp_mtrl3[12] = { 0,0,30,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl3[9] = { 15,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance3("Bacardi", disp_mtrl3, pump_mtrl3, TechniqueMethod::BUILD, 4, 255, 255, 255);

	int disp_mtrl4[12] = { 30,0,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl4[9] = { 60,0,0,0,0,15,0,0,0 };
	Cocktail cocktail_instance4("SeaBreeze", disp_mtrl4, pump_mtrl4, TechniqueMethod::BUILD, 2, 215, 60, 85);

	int disp_mtrl5[12] = { 0,0,0,0,0,45,0,0,0,0,0,0 };
	int pump_mtrl5[9] = { 0,0,0,60,0,0,0,0,0 };
	Cocktail cocktail_instance5("AppMartini", disp_mtrl5, pump_mtrl5, TechniqueMethod::BUILD, 4, 145, 220, 145);

	int disp_mtrl6[12] = { 30,0,0,0,15,0,0,0,0,0,0,0 };
	int pump_mtrl6[9] = { 15,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance6("Cosmopolitan", disp_mtrl6, pump_mtrl6, TechniqueMethod::BUILD, 4, 220, 145, 160);

	int disp_mtrl7[12] = { 0,0,0,30,0,0,0,0,0,0,0,0 };
	int pump_mtrl7[9] = { 15,0,0,0,90,0,0,0,0 };
	Cocktail cocktail_instance7("TequilaSunrise", disp_mtrl7, pump_mtrl7, TechniqueMethod::BUILD, 2, 255, 155, 55);

	int disp_mtrl8[12] = { 0,45,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl8[9] = { 0,15,0,0,0,0,15,0,0 };
	Cocktail cocktail_instance8("TomCollins", disp_mtrl8, pump_mtrl8, TechniqueMethod::BUILD, 2, 210, 240, 200);

	int disp_mtrl9[12] = {0,0,45,0,0,0,0,0,0,0,30,0};
	int pump_mtrl9[9] = {0,0,0,0,0,0,30,0,0 };
	Cocktail cocktail_instance9("Mohito", disp_mtrl9, pump_mtrl9, TechniqueMethod::BUILD, 3, 185, 230, 170);

	int disp_mtrl10[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl10[9] = {0,0,0,0,0,120,0,0,0 };
	Cocktail cocktail_instance10("SoltiDog", disp_mtrl10, pump_mtrl10, TechniqueMethod::BUILD, 1, 230, 200, 170);

	int disp_mtrl11[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl11[9] = {0,0,0,0,120,0,0,0,0 };
	Cocktail cocktail_instance11("ScrewDriver", disp_mtrl11, pump_mtrl11, TechniqueMethod::BUILD, 2, 255, 210, 1);

	int disp_mtrl12[12] = { 0,0,0,30,15,0,0,0,0,0,0,0 };
	int pump_mtrl12[9] = { 0,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance12("Margarita", disp_mtrl12, pump_mtrl12, TechniqueMethod::BUILD, 4, 205, 245, 200);

	int disp_mtrl13[12] = {0,0,0,0,0,0,0,30,0,0,0,0};
	int pump_mtrl13[9] = {60,0,0,60,0,0,0,0,0 };
	Cocktail cocktail_instance13("PitchCrush", disp_mtrl13, pump_mtrl13, TechniqueMethod::BUILD, 3, 255, 160, 160);

	int disp_mtrl14[12] = { 30,0,0,0,0,0,0,0,30,0,0,0 };
	int pump_mtrl14[9] = { 0,0,0,0,100,0,0,0,0 };
	Cocktail cocktail_instance14("BlueRomance", disp_mtrl14, pump_mtrl14, TechniqueMethod::BUILD, 3, 0, 130, 190);

	int disp_mtrl15[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl15[9] = {0,0,0,0,0,90,60,0,0 };
	Cocktail cocktail_instance15("JackHoneymong", disp_mtrl15, pump_mtrl15, TechniqueMethod::BUILD, 1, 175, 95, 95);

	int disp_mtrl16[12] = { 0,0,0,0,0,0,15,0,0,60,0,0 };
	int pump_mtrl16[9] = { 0,0,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance16("K-Cocktail", disp_mtrl16, pump_mtrl16, TechniqueMethod::BUILD, 2, 230, 210, 140);


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
}


// ************************* �ʱ�ȭ �Լ� *************************
// ���� ���¿� ��� ���� �ʱ�ȭ�� �Ͽ� ��밡���� ���·� ��������

void Operation::initialize() 
{
	// ���� �۵� ���� (1~8)
	for (int i = 0; i < 8; i++) {
		pump_arr[i]->stop_pump(i);
	}
	pinMode(38, OUTPUT);  digitalWrite(38, HIGH); // 9��° �Լ�
	pinMode(39, OUTPUT);  digitalWrite(39, HIGH);

	// �÷���Ʈ ��ġ (0,0)���� �ʱ�ȭ
	Plate p;
	p.move_to_initial_position(); // Ȥ�� �𸣴� ó�� ���������� ��

	// ���漭�� �������� �ʱ� ��ġ�� ��!
	Actuator a(22, 23);
	a.down();
	delay(6000);
	a.up();
	delay(2300);
	a.idle();

	// led ��Ʈ��, ��Ʈ���� ����
	p_ledstrip1->off();
	p_ledstrip2->off();
	p_ledpanel->off();

	// oled ȭ�� ���� �����
	Oled o;
	o.clear();

	// ���ͷ�
	pinMode(40, OUTPUT);  digitalWrite(40, HIGH);
	pinMode(41, OUTPUT);  digitalWrite(41, HIGH);

	Actuator a(42, 43);
	a.down();
	delay(6000);

	// ���̽� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ technique�� �ʱ�ȭ�Լ� ������
	/* ���� ���̽� ��ġ �ʱ�ȭ�ϴ� �Լ� */

}


// ************************* �Ҹ��� �Լ� **************************
Operation::~Operation() // �������� �Ҵ����� �ּҵ��� ������ �ش�.
{
	free(p_ledstrip1);
	free(p_ledstrip2);
	free(p_ledpanel);

	for (int i = 0; i < 9; i++) free(pump_arr[i]);
	for (int i = 0; i < 12; i++) free(disp_mtrl_arr[i]);
	for (int i = 0; i < 9; i++) free(pump_mtrl_arr[i]);
	for (int i = 0; i < 18; i++) free(cocktail_arr[i]);
}

// ********************** �۵��� ���� �Լ��� *********************

int Operation::select_make_recipe(String message)
{
	// �켱 message �� ���� & �� �ִ��� �˻�, ������ 18�� ��ȯ

	 // �־��� ���� -> �� ������ �迭 ����
	int disp_mtrl_amount[12] = { 0, };
	int pump_mtrl_amount[9] = { 0, };

	int i = 2; // message�� �ε���

	while (message[i] != '&') { // �޼����� ������ �˻�, ���̸� ��������
		String index = "";
		String amount = "";

		while (message[i] != '%') { // index ���� �޾ƿ���
			index += message[i];
			i++;
		} // end of internal while, %�� ������ ��������
		i++; // ������ index�� '%'�� ����Ű�� �����Ƿ� �Ʒ����� �ϳ� ����������.

		while (message[i] != '%' && message[i] != '&') { // amount ���� �޾ƿ���
			amount += message[i];
			i++;
		} // end of internal while, %�� ������ ��������

		// String �ڷ����� index�� amount�� int �ڷ������� �ٲ�
		int index_int = index.toInt();
		int amount_int = amount.toInt();

		// index�� 0~11�̸� disp mtrl, 12~20�̸� pump mtrl
		if (0 <= index_int && index_int <= 11) {
			disp_mtrl_amount[index_int] = amount_int;
		}
		else if (12 <= index_int && index_int <= 20) {
			pump_mtrl_amount[index_int - 12] = amount_int;
		}

		// ����: ������ �ε����� '%' �Ǵ� '&'�� ����Ű�� �ִ�.
	} // end of while: disp_mtrl_amount �� pump_mtrl_amount �迭 ���� �Ϸ�

	// Ĭ���� �ν��Ͻ� ����
	Cocktail my_cocktail("my_cocktail", disp_mtrl_amount, pump_mtrl_amount, 
		TechniqueMethod::BUILD, 123, 123, 123); // ������ ������ ��ũ�а� rgb @@@@@@@@@@@@@@@@@@@@@2

	// �����Ҵ� �� �ּ� ����
	cocktail_arr[17] = (Cocktail*)malloc(sizeof(my_cocktail));
	*(cocktail_arr[17]) = my_cocktail;

	// ����
	return 17;
}


int Operation::bluetooth_connect() {
	// SoftwareSerial�� �ƴ� Serial1 ���� �ٲ�� �� ���� ���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	SoftwareSerial bluetooth(18, 19); // pin Notation: RX, TX
	bluetooth.begin(9600);

	if (bluetooth.available()) {
		String str = "";
		while (bluetooth.available()) {
			char ch = bluetooth.read();
			delay(50); // ���ۿ� ���� �����͸� �������� �����ϴ� ���� ��ٸ��� �ð�
			str.concat(ch);
		}

		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ��ȣ �� �� 0~16���� 1~17����?
		//select_sample
		if (str.charAt(0) == '$') {
			String res = "";
			int i = 1;
			while (str.charAt(i) != '$') {
				char ch = str.charAt(i);
				res.concat(ch);
				i++;
			}
			return (res.toInt()); // 0~16 (���� ������ 16�� + �ñ״��� 1�� = 17��)
		}

		//make_recipe
		else if (str.charAt(0) == '&') {
			return select_make_recipe(str); // 17 (������ ���ǽ� or ���� ������)
		}

		else
			return 18; // ������� ��ȣ�� �޾����� ��ȿ�� ���� �ƴ� (����)
	}

	return -1; // ������� ��ȣ�� ���� ���� -> main���� ���� �ݺ�
}



// Ĭ������ ����� �Լ�
int Operation::make_cocktail(int result_index)
{
	Cocktail ct = *(cocktail_arr[result_index]);

	// ��Ʈ���� ���� �ν��Ͻ� ����;
	// Led, Pump �ν��Ͻ��� ������ ������ ������ ���
	Oled oled;
	Coord coord;
	Plate plate;

	// ����ϱ� ���� Ĭ���� �������� �̸� �������ش�.
	int* disp_recipe = ct.get_disp_recipe(); // ���� 12�� �迭
	int* pump_recipe = ct.get_pump_recipe(); // ���� 9�� �迭
	String ct_name = ct.get_name();
	char* name;
	ct_name.toCharArray(name, ct_name.length() + 1);
	int* ct_color = ct.get_cocktail_color(); // ���� 3�� �迭
	TechniqueMethod method = ct.get_technique();

	// ����� ��, OLED�� Ĭ���� �̸��� ǥ���ϰ� Led�� Ĭ���� ���� �Һ��� ����
	oled.display_right(name);
	p_ledpanel->color(ct_color);
	delay(5000);

	// ��ü ���� �󸶳� �Ǵ��� üũ
	int total_amount = 0;
	int now_amount = 0;

	for (int i = 0; i < 12; i++) {
		total_amount += disp_recipe[i];
	}
	for (int i = 0; i < 9; i++) {
		total_amount += pump_recipe[i];
	} // ���ͳ� ���̽��� �����Ͽ� �ڵ� ������ �� ���� **************************

	
	//�������׳� �� �ִ°ɷ�!?
	plate.moveto(5, 6);//*******************��ġ �׳� �ٷ� �־���_����Ȯ�� �� ����
	Technique t;
	t.add_ice(3);//*************������ ������ ���� �纸�� ����
	

	// �ܷ� üũ �ڵ带 ����� ��ü ���� ����ϴ� �ڵ带 ����. OLED�� ���൵�� ǥ���ϱ� ����
	// ���漭�� ����ϴ� ������ ����
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			DispenserMaterial material = *(disp_mtrl_arr[i]);
			String mtrl_name = material.get_name();

			// OLED ǥ��
			oled.display_progress(now_amount, total_amount, mtrl_name);
			total_amount += disp_recipe[i];

			// Led ���� ��� ������ ������ �ٲٱ�
			p_ledpanel->color(material.get_rgb());
			delay(1000); // �� �ٲٰ� 1�ʵ��� ��ٷ�

			// ��ǥ �����ϰ�, plate �����̱�
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.moveto(coord);
			delay(2000);

			// ��ǥ�� �̵������� �������� �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			plate.push_dispenser(disp_recipe[i]);

			delay(1000);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	// ���漭 ���� ������ ����ϴ� ��� ���
	for (int i = 0; i < 9; i++) {
		if (pump_recipe[i]) { // ���� �ش� ����� �����ǰ� 0�̸� �� ���� ������
		   // ���� �ڵ��� ���� �ش� �������� �ν��Ͻ� ����
			PumpMaterial material = *(pump_mtrl_arr[i]);
			String mtrl_name = material.get_name();

			// OLED ǥ��
			oled.display_progress(now_amount, total_amount, mtrl_name);
			total_amount += pump_recipe[i];

			// Led ���� ��� ������ ������ �ٲٱ�
			p_ledpanel->color(material.get_rgb());
			delay(1000); // �� �ٲٰ� 1�ʵ��� ��ٷ�

			// ��ǥ �����ϰ�, plate �����̱�
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.moveto(coord);
			delay(2000);

			// ��ǥ�� �̵������� !����! �۵� (�ش� �������� �翡 �ش��ϴ� �ð���ŭ)
			pump_arr[i]->work_pump(i,pump_recipe[i]);
			delay(1000);
		} // ��� �ϳ��� ������ ��������, �ٽ� �ٸ� ���� �� ������ �� ����
	}

	oled.display_progress(now_amount, total_amount, name);
	delay(3000);

	// ���� ����� ���� �����ϱ�
	p_ledpanel->color(ct_color); // �ش� Ĭ������ ���� �� ǥ��
	// �Լ� ������ ���� �ν��Ͻ� ����, ������ �������� method�� ������ �� ��� ����
	Technique t;
	t.f(method);

	// Ĭ���� �ϼ�!!
	oled.display_complete();    // OLED�� �Ϸ��ߴٰ� ǥ��
	plate.move_to_initial_position();    // move to init pos

	return 1; // ���� �ڵ� 1: Ĭ���� �ϼ�
}


void Operation::emergency_stop()
{
	Oled o;
	o.display_center("emergency stop!");

	// ���� �Ҵ� ����
	free(p_ledstrip1);
	free(p_ledstrip2);
	free(p_ledpanel);

	for (int i = 0; i < 9; i++) free(pump_arr[i]);
	for (int i = 0; i < 12; i++) free(disp_mtrl_arr[i]);
	for (int i = 0; i < 9; i++) free(pump_mtrl_arr[i]);
	for (int i = 0; i < 18; i++) free(cocktail_arr[i]);

	exit(1); // ���� �ڵ� 1: ��ȿ�� ������� �Է� ��
}


#endif