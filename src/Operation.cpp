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
	//dispenser_material_list가 배열
	DispenserMaterial* dispenser_material_list;
	dispenser_material_list = (DispenserMaterial*)malloc(sizeof(DispenserMaterial) * 12);
	
	//dispmaterial_instance 생성
	DispenserMaterial extern dispmaterial_instance1;
	DispenserMaterial extern dispmaterial_instance2;
	DispenserMaterial extern dispmaterial_instance3;
	DispenserMaterial extern dispmaterial_instance4;
	DispenserMaterial extern dispmaterial_instance5;
	DispenserMaterial extern dispmaterial_instance6;
	DispenserMaterial extern dispmaterial_instance7;
	DispenserMaterial extern dispmaterial_instance8;
	DispenserMaterial extern dispmaterial_instance9;
	DispenserMaterial extern dispmaterial_instance10;
	DispenserMaterial extern dispmaterial_instance11;
	DispenserMaterial extern dispmaterial_instance12;

	//여기에도 extern을 써야겟지..?
	p_dispmaterial_instance1 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance1));
	p_dispmaterial_instance2 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance2));
	p_dispmaterial_instance3 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance3));
	p_dispmaterial_instance4 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance4));
	p_dispmaterial_instance5 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance5));
	p_dispmaterial_instance6 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance6));
	p_dispmaterial_instance7 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance7));
	p_dispmaterial_instance8 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance8));
	p_dispmaterial_instance9 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance9));
	p_dispmaterial_instance10 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance10));
	p_dispmaterial_instance11 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance11));
	p_dispmaterial_instance12 = (DispenserMaterial*)malloc(sizeof(extern dispmaterial_instance12));

	*(p_dispmaterial_instance1) = dispenser_material_list[0];
	*(p_dispmaterial_instance2) = dispenser_material_list[1];
	*(p_dispmaterial_instance3) = dispenser_material_list[2];
	*(p_dispmaterial_instance4) = dispenser_material_list[3];
	*(p_dispmaterial_instance5) = dispenser_material_list[4];
	*(p_dispmaterial_instance6) = dispenser_material_list[5];
	*(p_dispmaterial_instance7) = dispenser_material_list[6];
	*(p_dispmaterial_instance8) = dispenser_material_list[7];
	*(p_dispmaterial_instance9) = dispenser_material_list[8];
	*(p_dispmaterial_instance10) = dispenser_material_list[9];
	*(p_dispmaterial_instance11) = dispenser_material_list[10];
	*(p_dispmaterial_instance12) = dispenser_material_list[11];

	
}

void Operation::preset_pump_materials()
{
	//pump_material_list가 배열
	PumpMaterial* pump_material_list;
	pump_material_list = (PumpMaterial*)malloc(sizeof(PumpMaterial) * 7);

	//pumpmaterial_instance 생성
	PumpMaterial extern pumpmaterial_instance1;
	PumpMaterial extern pumpmaterial_instance2;
	PumpMaterial extern pumpmaterial_instance3;
	PumpMaterial extern pumpmaterial_instance4;
	PumpMaterial extern pumpmaterial_instance5;
	PumpMaterial extern pumpmaterial_instance6;
	PumpMaterial extern pumpmaterial_instance7;
	

	p_pumpmaterial_instance1 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance1));
	p_pumpmaterial_instance2 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance2));
	p_pumpmaterial_instance3 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance3));
	p_pumpmaterial_instance4 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance4));
	p_pumpmaterial_instance5 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance5));
	p_pumpmaterial_instance6 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance6));
	p_pumpmaterial_instance7 = (PumpMaterial*)malloc(sizeof(extern pumpmaterial_instance7));
	

	*(p_dispmaterial_instance1) = pump_material_list[0];
	*(p_dispmaterial_instance2) = pump_material_list[1];
	*(p_dispmaterial_instance3) = pump_material_list[2];
	*(p_dispmaterial_instance4) = pump_material_list[3];
	*(p_dispmaterial_instance5) = pump_material_list[4];
	*(p_dispmaterial_instance6) = pump_material_list[5];
	*(p_dispmaterial_instance7) = pump_material_list[6];

}

void Operation::preset_cocktail_recipes()
{
	//cocktail_list가 배열
	Cocktail* cocktail_list;
	cocktail_list = (Cocktail*)malloc(sizeof(Cocktail) * 7);//칵테일은 그럼 총 몇개인가...
	

	//cocktail_instance 생성
	Cocktail extern cocktail_instance1;
	Cocktail extern cocktail_instance2;
	Cocktail extern cocktail_instance3;
	Cocktail extern cocktail_instance4;
	Cocktail extern cocktail_instance5;
	Cocktail extern cocktail_instance6;
	Cocktail extern cocktail_instance7;


	p_cocktail_instance1 = (Cocktail*)malloc(sizeof(extern cocktail_instance1));
	p_cocktail_instance2 = (Cocktail*)malloc(sizeof(extern cocktail_instance2));
	p_cocktail_instance3 = (Cocktail*)malloc(sizeof(extern cocktail_instance3));
	p_cocktail_instance4 = (Cocktail*)malloc(sizeof(extern cocktail_instance4));
	p_cocktail_instance5 = (Cocktail*)malloc(sizeof(extern cocktail_instance5));
	p_cocktail_instance6 = (Cocktail*)malloc(sizeof(extern cocktail_instance6));
	p_cocktail_instance7 = (Cocktail*)malloc(sizeof(extern cocktail_instance7));


	*(p_cocktail_instance1) = cocktail_list[0];
	*(p_cocktail_instance2) = cocktail_list[1];
	*(p_cocktail_instance3) = cocktail_list[2];
	*(p_cocktail_instance4) = cocktail_list[3];
	*(p_cocktail_instance5) = cocktail_list[4];
	*(p_cocktail_instance6) = cocktail_list[5];
	*(p_cocktail_instance7) = cocktail_list[6];

	
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

/*************이걸 이렇게 만들까 아님 메인에다가 할까 함수들*********************/
//블루투스 연결 확인+첫번째 선택(샘플/나만의 레시피/시그니쳐)
void Operation::bluetooth_connect()//preset_bluetooth()로 할까
{
	if (blueToothSerial.available()) {
		char message = blueToothSerial.read();
		if (message <= '0' && message <= '15') {//어플에서 char형으로 보내야됨, 이 숫자는 Sample_list의 index
			material_instance = Sample_list[message];
			return material_instance;
		}		
	}
}

//recipe를 선택할 때(귀찮으니까 재료3개 입력 제한)
void Operation::select_makerecipe()
{
	char* material_list[3][2];
	for (int i = 0; i < 3; i++) {
		if (blueToothSerial.available()) {
			char* my_material = blueToothSerial.read();
			material_list[i][1] = my_material;
			char* my_materialvol = blueToothSerial.read();
			material_list[i][2] = my_materialvol;
		}
	}
	//return material_list;
	//ㄴ여기서 잘라서 잘라서 material_list return해줄까..

	//{char형 material(숫자),양}이 3개있는 material_list만들어짐----여기서 숫자는 Material_list[]의 index랑 맞춰야함
	//저장된 Material들이 모여있는 array를 Material_list[]라 한다
	//ㄴdisp, pump랑 구별하기 쉽도록 먼저 disp_material쓰고 나중에 pump_material쓰는 식으로 해서 쉽게 가자..(숫자로 구별하자는 말)
	//하나씩 접근해서 Material instance 생성
	//근데 이거 이름밖에 없어서 material이름만 저장된 list에서 찾아줘야 할까
	//이렇게 만들어진 material_list에서 하나씩접근해서 Material instance 만들어서 반복하는게 best일듯->이거는 그냥 main에다가??

	for (int i = 0; i < 3; i++) {
		Material material_instance = Material_list[i];
		//Mateirl 변수 하나 만들어짐
		//ㄴmain에다가 위에걸쓸거면 만들어진 Mateirial instance의 member?를 바로 oled,plate,led,actuator에 넣어준다
		//ㄴ이걸 operation class의 함수로 만들거면 return Material material_instance;해서 진행	
	}
}

//저장된 레시피를 material instance로 분리하는 함수(material.cpp에 넣어도 괜찮을듯)
void Operation::change_to_materialclass(int i) {
	

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