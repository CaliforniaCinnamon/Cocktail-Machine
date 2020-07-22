// 
// 임포트 한 클래스들이 많이 바뀌어서, 어차피 얘도 많이 바꿔야함.
// 

#if 0

#include "Material.h"
#include "Operation.h"
#include <SoftwareSerial.h>


// ******************** main의 전역 포인터 가져오기 ******************
extern Led* p_ledstrip1;  extern Led* p_ledstrip2;  
extern Led* p_ledpanel;
extern Pump* p_pump1;  extern Pump* p_pump2;  
extern Pump* p_pump3;  extern Pump* p_pump4;
extern Pump* p_pump5;  extern Pump* p_pump6;  
extern Pump* p_pump7;

extern DispenserMaterial* disp_mtrl_arr[12];
extern PumpMaterial* pump_mtrl_arr[7];
extern Cocktail* cocktail_arr[18];


// *************************** 프리셋 함수들 *************************
void Operation::preset_led_instances()
{
	Led ledstrip1(50, 31); // led 개수, 핀넘버
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
	Pump pump1(23, 24); // 핀A, 핀B
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

// 정보 셋업하기 (재료들의 위치, 칵테일 레시피)
void Operation::preset_dispenser_materials() 
{
	//dispenser_material_instance 생성
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
	
	
	auto p_dispmaterial_instance1 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance1));
	auto p_dispmaterial_instance2 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance2));
	auto p_dispmaterial_instance3 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance3));
	auto p_dispmaterial_instance4 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance4));
	auto p_dispmaterial_instance5 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance5));
	auto p_dispmaterial_instance6 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance6));
	auto p_dispmaterial_instance7 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance7));
	auto p_dispmaterial_instance8 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance8));
	auto p_dispmaterial_instance9 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance9));
	auto p_dispmaterial_instance10 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance10));
	auto p_dispmaterial_instance11 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance11));
	auto p_dispmaterial_instance12 = (DispenserMaterial*)malloc(sizeof(dispmaterial_instance12));
	
	disp_mtrl_arr[0] = *(p_dispmaterial_instance1);
	disp_mtrl_arr[1] = *(p_dispmaterial_instance2);
	disp_mtrl_arr[2] = *(p_dispmaterial_instance3);
	disp_mtrl_arr[3] = *(p_dispmaterial_instance4);
	disp_mtrl_arr[4] = *(p_dispmaterial_instance5);
	disp_mtrl_arr[5] = *(p_dispmaterial_instance6);
	disp_mtrl_arr[6] = *(p_dispmaterial_instance7);
	disp_mtrl_arr[7] = *(p_dispmaterial_instance8);
	disp_mtrl_arr[8] = *(p_dispmaterial_instance9);
	disp_mtrl_arr[9] = *(p_dispmaterial_instance10);
	disp_mtrl_arr[10] = *(p_dispmaterial_instance11);
	disp_mtrl_arr[11] = *(p_dispmaterial_instance12);
	
}

void Operation::preset_pump_materials()
{
	//pump_material_instance 생성
	//PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	PumpMaterial pumpmaterial_instance1("Rasp", 0, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance2("Lemon", 1, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance3("Lime", 2, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance4("Sweet", 3, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance5("Orange", 4, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance6("Grp", 5, 750, 200, 200, 200);
	PumpMaterial pumpmaterial_instance7("Tonic", 6, 750, 200, 200, 200);
	

	auto p_pumpmaterial_instance1 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance1));
	auto p_pumpmaterial_instance2 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance2));
	auto p_pumpmaterial_instance3 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance3));
	auto p_pumpmaterial_instance4 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance4));
	auto p_pumpmaterial_instance5 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance5));
	auto p_pumpmaterial_instance6 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance6));
	auto p_pumpmaterial_instance7 = (PumpMaterial*)malloc(sizeof(pumpmaterial_instance7));
	

	pump_mtrl_arr[0] = *(p_pumpmaterial_instance1);
	pump_mtrl_arr[1] = *(p_pumpmaterial_instance2);
	pump_mtrl_arr[2] = *(p_pumpmaterial_instance3);
	pump_mtrl_arr[3] = *(p_pumpmaterial_instance4);
	pump_mtrl_arr[4] = *(p_pumpmaterial_instance5);
	pump_mtrl_arr[5] = *(p_pumpmaterial_instance6);
	pump_mtrl_arr[6] = *(p_pumpmaterial_instance7);
	

}

void Operation::preset_cocktail_recipes()
{
	//cocktail_instance 생성
	// 이름은 "Martini" 이렇게 받고, 배열은 주소로 받음. 기법은 BUILD STIR 이렇게 써주면 됨.
	//Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],	TechniqueMethod a_method, int a_r, int a_g, int a_b);
	int disp_mtrl1[12] = {0,0,45,0,0,0,0,0,0,0,0,0};
	int pump_mtrl1[7] = {};
	Cocktail cocktail_instance1("Daiquiri",disp_mtrl1,pump_mtrl1,BUILD,50,1,5);

	int disp_mtrl2[12] = {};
	int pump_mtrl2[7] = {};
	Cocktail cocktail_instance2("Longisland", disp_mtrl2, pump_mtrl2, BUILD, 50, 1, 5);

	int disp_mtrl3[12] = {};
	int pump_mtrl3[7] = {};
	Cocktail cocktail_instance3("Bacardi", disp_mtrl3, pump_mtrl3, BUILD, 50, 1, 5);

	int disp_mtrl4[12] = {};
	int pump_mtrl4[7] = {};
	Cocktail cocktail_instance4("ShiBreeze", disp_mtrl4, pump_mtrl4, BUILD, 50, 1, 5);

	int disp_mtrl5[12] = {};
	int pump_mtrl5[7] = {};
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


	auto p_cocktail_instance1 = (Cocktail*)malloc(sizeof(cocktail_instance1));
	auto p_cocktail_instance2 = (Cocktail*)malloc(sizeof(cocktail_instance2));
	auto p_cocktail_instance3 = (Cocktail*)malloc(sizeof(cocktail_instance3));
	auto p_cocktail_instance4 = (Cocktail*)malloc(sizeof(cocktail_instance4));
	auto p_cocktail_instance5 = (Cocktail*)malloc(sizeof(cocktail_instance5));
	auto p_cocktail_instance6 = (Cocktail*)malloc(sizeof(cocktail_instance6));
	auto p_cocktail_instance7 = (Cocktail*)malloc(sizeof(cocktail_instance7));
	auto p_cocktail_instance8 = (Cocktail*)malloc(sizeof(cocktail_instance8));
	auto p_cocktail_instance9 = (Cocktail*)malloc(sizeof(cocktail_instance9));
	auto p_cocktail_instance10 = (Cocktail*)malloc(sizeof(cocktail_instance10));
	auto p_cocktail_instance11 = (Cocktail*)malloc(sizeof(cocktail_instance11));
	auto p_cocktail_instance12 = (Cocktail*)malloc(sizeof(cocktail_instance12));
	auto p_cocktail_instance13 = (Cocktail*)malloc(sizeof(cocktail_instance13));
	auto p_cocktail_instance14 = (Cocktail*)malloc(sizeof(cocktail_instance14));
	auto p_cocktail_instance15 = (Cocktail*)malloc(sizeof(cocktail_instance15));
	auto p_cocktail_instance16 = (Cocktail*)malloc(sizeof(cocktail_instance16));
	auto p_cocktail_instance17 = (Cocktail*)malloc(sizeof(cocktail_instance17));
	auto p_cocktail_instance18 = (Cocktail*)malloc(sizeof(cocktail_instance18));


	cocktail_arr[0] = *(p_cocktail_instance1);
	cocktail_arr[1] = *(p_cocktail_instance2);
	cocktail_arr[2] = *(p_cocktail_instance3);
	cocktail_arr[3] = *(p_cocktail_instance4);
	cocktail_arr[4] = *(p_cocktail_instance5);
	cocktail_arr[5] = *(p_cocktail_instance6);
	cocktail_arr[6] = *(p_cocktail_instance7);
	cocktail_arr[7] = *(p_cocktail_instance8);
	cocktail_arr[8] = *(p_cocktail_instance9);
	cocktail_arr[9] = *(p_cocktail_instance10);
	cocktail_arr[10] = *(p_cocktail_instance11);
	cocktail_arr[11] = *(p_cocktail_instance12);
	cocktail_arr[12] = *(p_cocktail_instance13);
	cocktail_arr[13] = *(p_cocktail_instance14);
	cocktail_arr[14] = *(p_cocktail_instance15);
	cocktail_arr[15] = *(p_cocktail_instance16);
	cocktail_arr[16] = *(p_cocktail_instance17);
	cocktail_arr[17] = *(p_cocktail_instance18);

}



// ************************* 소멸자 함수 **************************
Operation::~Operation() // 동적으로 할당해준 주소들을 해제해 준다.
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

// ********************** 작동을 위한 함수들 *********************
void Operation::bluetooth_connect()//preset_bluetooth()로 할까
{
	if (blueToothSerial.available()) {
		char message = blueToothSerial.read();
		if (message <= '0' && message <= '15') {//어플에서 char형으로 보내야됨
		   //OLED 문자 출력 "Bluetooth is connected"
			delay(3000);
			//LED 스트립 on
			delay(3000);
		}
	}
}


// 함수 여러개로 분할할까...-> 분할하는게 좋을거라 생각했는데 좀 애매하네..(인스턴스 생성함수/디스펜서+펌프/
int Operation::make_cocktail(Cocktail ct)
{
	// creating temp instances
	// 얘네들을 어떻게 처리할까? 
	// 그냥 인스턴스 생성해서 쓰는거면 프리셋도 필요 없겠는데...->led,oled 프리셋 함수는 화면 비우는 걸 생각하신건가요??
	Oled oled_instance;
	LedStrip led_instance;
	Coord coord_instance;
	Plate plate_instance;
	Pump pump_instance;


	// checking remains...


	// OLED display name of the cocktail
	string name = ct.get_name();
	oled_instance.display_character(name); // 함수 이름은 바뀔 수 있음.


	/*
	중간에 몇 초 동안 기다리는 함수 아직 안 넣음!!
	*/
	// loop; num of alcohol; 디스펜서 개수만큼 반복...
	auto disp_recipe = ct.get_disp_recipe();
	for (auto it = disp_recipe.begin(); it != disp_recipe.end(); it++)
	{
		DispenserMaterial material = it->first;

		// OLED display alcohol
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // 함수 이름 달라질 수 있음

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// move plate z-axis (push dispenser)
		plate_instance.push_dispenser(it->second);
	}


	// loop; num of non-alcohol material; 디스펜서 개수만큼 반복...
	auto pump_recipe = ct.get_pump_recipe();
	for (auto it = pump_recipe.begin(); it != pump_recipe.end(); it++)
	{
		PumpMaterial material = it->first;

		// OLED display non-alcohol material
		oled_instance.display_charcater(material.get_name());

		// LedStrip set color
		int* p_rgb = material.get_rgb();
		led_instance.set_color(p_rgb[0], p_rgb[1], p_rgb[2]); // 함수 이름 달라질 수 있음

		// move plate
		coord_instance.set(material.get_pos_x(), material.get_pos_y());
		plate_instance.move_horizontally(coord_instance);

		// activate pump
		pump_instance.work_pump(it->second); // 이것 역시 함수 이름 달라질 수 있음
	}


	// 주조 기법에 따라 주조하기
	Technique ct_technique;
	ct_technique.f(ct.get_craft_method());


	// move to init pos
	plate_instance.move_to_initial_position();

	// OLED display 'complete'
	oled_instance.display_character("complete!"); // 완료 문구 달라질 수 있음

	return 0;
}


int Operation::emergency_stop()
{
	print("emergency stop!");
	exit;
	return 0;
}


#endif