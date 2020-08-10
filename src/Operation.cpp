// 
// 임포트 한 클래스들이 많이 바뀌어서, 어차피 얘도 많이 바꿔야함.
// 

#if 1

#include "Operation.h"

// ******************** main의 전역 포인터 가져오기 ******************

// global variable


// *************************** 프리셋 함수들 *************************

    // 정보 셋업하기 (재료들의 위치, 칵테일 레시피)
void Operation::preset_dispenser_materials()
{
	//dispenser_material_instance 생성
	//DispenserMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	DispenserMaterial dispmaterial_instance1("Vodka", 0, 750, 250, 250, 250);
	EEPROM.put(eeprom_adrs, dispmaterial_instance1);

	mtrl_size = sizeof(dispmaterial_instance1);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance2("Jean", 1, 750, 180, 220, 220);
	EEPROM.put(eeprom_adrs, dispmaterial_instance2);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance3("WhiteRum", 2, 750, 250, 250, 250);
	EEPROM.put(eeprom_adrs, dispmaterial_instance3);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance4("Tequila", 3, 750, 240, 240, 95);
	EEPROM.put(eeprom_adrs, dispmaterial_instance4);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance5("Cuentro", 4, 750, 210, 145, 45);
	EEPROM.put(eeprom_adrs, dispmaterial_instance5);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance6("Smynov", 5, 750, 130, 225, 120);
	EEPROM.put(eeprom_adrs, dispmaterial_instance6);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance7("Soju", 6, 360, 130, 225, 120);
	EEPROM.put(eeprom_adrs, dispmaterial_instance7);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance8("Peach", 7, 750, 250, 160, 205);
	EEPROM.put(eeprom_adrs, dispmaterial_instance8);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance9("BlueCurasso", 8, 750, 60, 60, 210);
	EEPROM.put(eeprom_adrs, dispmaterial_instance9);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance10("Beer", 9, 500, 110, 65, 100);
	EEPROM.put(eeprom_adrs, dispmaterial_instance10);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance11("Mohito", 10, 750, 130, 215, 125);
	EEPROM.put(eeprom_adrs, dispmaterial_instance11);
	eeprom_adrs += sizeof(mtrl_size);

	DispenserMaterial dispmaterial_instance12("JackDaniel", 11, 750, 210, 140, 60);
	EEPROM.put(eeprom_adrs, dispmaterial_instance12);
	eeprom_adrs += sizeof(mtrl_size);

}

void Operation::preset_pump_materials()
{
	eeprom_pump_start_adrs = eeprom_adrs;

	//pump_material_instance 생성
	//PumpMaterial(String aname, int a_num, double a_remain, int ar, int ag, int ab)
	PumpMaterial pumpmaterial_instance1("Raspberry", 13, 750, 200, 50, 40);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance1);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance2("Lemon", 14, 750, 255, 255, 10);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance2);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance3("Lime", 15, 750, 120, 210, 100);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance3);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance4("Sweet & Sour", 16, 750, 230, 230, 100);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance4);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance5("Orange", 17, 750, 255, 130, 0);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance5);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance6("Grapefruit juice", 18, 750, 255, 185, 115);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance6);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance7("Tonic", 19, 750, 255, 255, 255);
	EEPROM.put(eeprom_adrs, pumpmaterial_instance7);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance8("Unknwon1", 20, 750, 128, 64, 64); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	EEPROM.put(eeprom_adrs, pumpmaterial_instance8);
	eeprom_adrs += sizeof(mtrl_size);

	PumpMaterial pumpmaterial_instance9("Unknwon2", 21, 750, 255, 255, 255); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	EEPROM.put(eeprom_adrs, pumpmaterial_instance9);
	eeprom_adrs += sizeof(mtrl_size);


}

void Operation::preset_cocktail_recipes()
{
	eeprom_cocktail_start_adrs = eeprom_adrs;

	//cocktail_instance 생성
	// 이름은 "Martini" 이렇게 받고, 배열은 주소로 받음. 기법은 BUILD STIR 이렇게 써주면 됨.
	//Cocktail(String name, int a_disp_mtrl[], int a_pump_mtrl[],   TechniqueMethod a_method, int glass, int a_r, int a_g, int a_b);
	//glass는 작은 것부터 1,2,3,4
	int disp_mtrl1[12] = { 0,0,45,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl1[9] = {0,0,20,0,0,0,0,0,0};
	Cocktail cocktail_instance1("Daiquiri", disp_mtrl1, pump_mtrl1, TechniqueMethod::STIR, 4, 200, 255, 150);
	EEPROM.put(eeprom_adrs, cocktail_instance1);

	cocktail_size = sizeof(cocktail_instance1);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl2[12] = { 15,15,15,15,15,0,0,0,0,0,0,0 };
	int pump_mtrl2[9] = { 0,30,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance2("Longisland", disp_mtrl2, pump_mtrl2, TechniqueMethod::BUILD, 3, 115, 60, 60);
	EEPROM.put(eeprom_adrs, cocktail_instance2);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl3[12] = { 0,0,30,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl3[9] = { 15,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance3("Bacardi", disp_mtrl3, pump_mtrl3, TechniqueMethod::STIR, 4, 255, 255, 255);
	EEPROM.put(eeprom_adrs, cocktail_instance3);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl4[12] = { 30,0,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl4[9] = { 60,0,0,0,0,15,0,0,0 };
	Cocktail cocktail_instance4("SeaBreeze", disp_mtrl4, pump_mtrl4, TechniqueMethod::BUILD, 2, 215, 60, 85);
	EEPROM.put(eeprom_adrs, cocktail_instance4);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl5[12] = { 0,0,0,0,0,45,0,0,0,0,0,0 };
	int pump_mtrl5[9] = { 0,0,0,60,0,0,0,0,0 };
	Cocktail cocktail_instance5("AppMartini", disp_mtrl5, pump_mtrl5, TechniqueMethod::STIR, 4, 145, 220, 145);
	EEPROM.put(eeprom_adrs, cocktail_instance5);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl6[12] = { 30,0,0,0,15,0,0,0,0,0,0,0 };
	int pump_mtrl6[9] = { 15,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance6("Cosmopolitan", disp_mtrl6, pump_mtrl6, TechniqueMethod::STIR, 4, 220, 145, 160);
	EEPROM.put(eeprom_adrs, cocktail_instance6);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl7[12] = { 0,0,0,30,0,0,0,0,0,0,0,0 };
	int pump_mtrl7[9] = { 15,0,0,0,90,0,0,0,0 };
	Cocktail cocktail_instance7("TequilaSunrise", disp_mtrl7, pump_mtrl7, TechniqueMethod::BUILD, 2, 255, 155, 55);
	EEPROM.put(eeprom_adrs, cocktail_instance7);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl8[12] = { 0,45,0,0,0,0,0,0,0,0,0,0 };
	int pump_mtrl8[9] = { 0,15,0,0,0,0,15,0,0 };
	Cocktail cocktail_instance8("TomCollins", disp_mtrl8, pump_mtrl8, TechniqueMethod::STIR, 2, 210, 240, 200);
	EEPROM.put(eeprom_adrs, cocktail_instance8);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl9[12] = {0,0,45,0,0,0,0,0,0,0,30,0};
	int pump_mtrl9[9] = {0,0,0,0,0,0,30,0,0 };
	Cocktail cocktail_instance9("Mohito", disp_mtrl9, pump_mtrl9, TechniqueMethod::BUILD, 3, 185, 230, 170);
	EEPROM.put(eeprom_adrs, cocktail_instance9);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl10[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl10[9] = {0,0,0,0,0,120,0,0,0 };
	Cocktail cocktail_instance10("SoltiDog", disp_mtrl10, pump_mtrl10, TechniqueMethod::BUILD, 1, 230, 200, 170);
	EEPROM.put(eeprom_adrs, cocktail_instance10);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl11[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl11[9] = {0,0,0,0,120,0,0,0,0 };
	Cocktail cocktail_instance11("ScrewDriver", disp_mtrl11, pump_mtrl11, TechniqueMethod::BUILD, 2, 255, 210, 1);
	EEPROM.put(eeprom_adrs, cocktail_instance11);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl12[12] = { 0,0,0,30,15,0,0,0,0,0,0,0 };
	int pump_mtrl12[9] = { 0,0,15,0,0,0,0,0,0 };
	Cocktail cocktail_instance12("Margarita", disp_mtrl12, pump_mtrl12, TechniqueMethod::STIR, 4, 205, 245, 200);
	EEPROM.put(eeprom_adrs, cocktail_instance12);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl13[12] = {0,0,0,0,0,0,0,30,0,0,0,0};
	int pump_mtrl13[9] = {60,0,0,60,0,0,0,0,0 };
	Cocktail cocktail_instance13("PitchCrush", disp_mtrl13, pump_mtrl13, TechniqueMethod::BUILD, 3, 255, 160, 160);
	EEPROM.put(eeprom_adrs, cocktail_instance13);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl14[12] = { 30,0,0,0,0,0,0,0,30,0,0,0 };
	int pump_mtrl14[9] = { 0,0,0,0,100,0,0,0,0 };
	Cocktail cocktail_instance14("BlueRomance", disp_mtrl14, pump_mtrl14, TechniqueMethod::STIR, 3, 0, 130, 190);
	EEPROM.put(eeprom_adrs, cocktail_instance14);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl15[12] = {30,0,0,0,0,0,0,0,0,0,0,0};
	int pump_mtrl15[9] = {0,0,0,0,0,90,60,0,0 };
	Cocktail cocktail_instance15("JackHoneymong", disp_mtrl15, pump_mtrl15, TechniqueMethod::BUILD, 1, 175, 95, 95);
	EEPROM.put(eeprom_adrs, cocktail_instance15);
	eeprom_adrs += sizeof(cocktail_size);

	int disp_mtrl16[12] = { 0,0,0,0,0,0,15,0,0,60,0,0 };
	int pump_mtrl16[9] = { 0,0,0,0,0,0,0,0,0 };
	Cocktail cocktail_instance16("K-Cocktail", disp_mtrl16, pump_mtrl16, TechniqueMethod::BUILD, 2, 230, 210, 140);
	EEPROM.put(eeprom_adrs, cocktail_instance16);
	eeprom_adrs += sizeof(cocktail_size);
}


// ************************* 초기화 함수 *************************
// 현재 상태와 상관 없이 초기화를 하여 사용가능한 상태로 만들어야함

void Operation::initialize() 
{
	// 펌프 작동 중지 (1~8)
	Pump pump_instance;
	for (int i = 0; i < 8; i++) {
		pump_instance.stop_pump(i + 1);
	}
	pinMode(38, OUTPUT);  digitalWrite(38, HIGH); // 9번째 함수
	pinMode(39, OUTPUT);  digitalWrite(39, HIGH);

	// 플레이트 위치 (0,0)으로 초기화
	Plate p;
	p.move_to_initial_position(); // 혹시 모르니 처음 포지션으로 가

	// 디스펜서용 액츄에이터 초기 위치로 가!
	Actuator disp_act(22, 23);
	disp_act.down();
	delay(6000);
	disp_act.up();
	delay(2300);
	disp_act.idle();

	// led 스트립, 매트릭스 끄기
	Led ledstrip1(55, 3); // led 개수, 핀넘버
	Led ledstrip2(55, 4);
	Led ledpanel(256, 2);
	ledstrip1.off();
	ledstrip2.off();
	ledpanel.off();

	// oled 화면 전부 지우기
	Oled o;
	o.clear();

	// 스터러 모터 브레이크
	pinMode(40, OUTPUT);  digitalWrite(40, HIGH);
	pinMode(41, OUTPUT);  digitalWrite(41, HIGH);

	// 스터러 액츄에이터 맨 위로 올라가기
	Actuator stir_act(42, 43);
	stir_act.down();
	delay(6000);

	// 아이스 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ technique에 초기화함수 만들자
	/* 대충 아이스 장치 초기화하는 함수 */

}


// ********************** 작동을 위한 함수들 *********************

int Operation::select_make_recipe(String message)
{
	// 우선 message 양 끝에 & 가 있는지 검사, 없으면 18을 반환

	 // 주어진 정보 -> 양 데이터 배열 선언
	int disp_mtrl_amount[12] = { 0, };
	int pump_mtrl_amount[9] = { 0, };

	int i = 2; // message의 인덱스

	while (message[i] != '&') { // 메세지의 끝인지 검사, 끝이면 빠져나옴
		String index = "";
		String amount = "";

		while (message[i] != '%') { // index 정보 받아오기
			index += message[i];
			i++;
		} // end of internal while, %를 만나면 빠져나옴
		i++; // 지금의 index는 '%'를 가리키고 있으므로 아래에서 하나 증가시켜줌.

		while (message[i] != '%' && message[i] != '&') { // amount 정보 받아오기
			amount += message[i];
			i++;
		} // end of internal while, %를 만나면 빠져나옴

		// String 자료형의 index와 amount를 int 자료형으로 바꿈
		int index_int = index.toInt();
		int amount_int = amount.toInt();

		// index가 0~11이면 disp mtrl, 12~20이면 pump mtrl
		if (0 <= index_int && index_int <= 11) {
			disp_mtrl_amount[index_int] = amount_int;
		}
		else if (12 <= index_int && index_int <= 20) {
			pump_mtrl_amount[index_int - 12] = amount_int;
		}

		// 참고: 지금의 인덱스는 '%' 또는 '&'를 가리키고 있다.
	} // end of while: disp_mtrl_amount 와 pump_mtrl_amount 배열 설정 완료

	// 칵테일 인스턴스 생성
	Cocktail my_cocktail("my_cocktail", disp_mtrl_amount, pump_mtrl_amount, 
		TechniqueMethod::BUILD, 4, 121, 0, 214); // 나만의 레시피 테크닉과 rgb @@@@@@@@@@@@@@@@@@@@@2

	// eeprom 칵테일 18번째 주소에 덮어쓰기
	EEPROM.put(eeprom_cocktail_start_adrs + 17 * cocktail_size, my_cocktail);

	// 리턴
	return 17;
}


int Operation::bluetooth_connect() 
{
	Serial1.begin(9600);

	if (Serial1.available()) {
		String str = "";
		while (Serial1.available()) {
			char ch = Serial1.read();
			delay(50); // 버퍼에 쌓인 데이터를 가져오고 삭제하는 것을 기다리는 시간
			str.concat(ch);
		}

		//select_sample
		if (str.charAt(0) == '$') {
			String res = "";
			int i = 1;
			while (str.charAt(i) != '$') {
				char ch = str.charAt(i);
				res.concat(ch);
				i++;
			}
			return (res.toInt() - 1); // 0~16 (원래 레시피 16개 + 시그니쳐 1개 = 17개)
		}

		//make_recipe
		else if (str.charAt(0) == '&') {
			return select_make_recipe(str); // 17 (나만의 레피시 or 랜덤 레시피)
		}

		else
			return 18; // 블루투스 신호를 받았지만 유효한 값이 아님 (에러)
	}

	return -1; // 블루투스 신호를 받지 못함 -> main에서 루프 반복
}



// 칵테일을 만드는 함수
int Operation::make_cocktail(int result_index)
{
	// eeprom에 저장된 칵테일 정보 꺼내오기
	int disp_mtrl_tmp[12] = { 0, };
	int pump_mtrl_tmp[9] = { 0, };
	Cocktail ct("tmp_cocktail", disp_mtrl_tmp, pump_mtrl_tmp, TechniqueMethod::BUILD, 1, 0, 0, 0);
	EEPROM.get(eeprom_cocktail_start_adrs + result_index * cocktail_size, ct);

	// 컨트롤을 위한 인스턴스 생성;
	Oled oled;
	Coord coord;
	Plate plate;
	Led ledstrip1(55, 3); // led 개수, 핀넘버
	Led ledstrip2(55, 4);
	Led ledpanel(256, 2);
	Pump pump_instance;

	// 사용하기 쉽게 칵테일 정보들을 미리 선언해준다.
	int* disp_recipe = ct.get_disp_recipe(); // 원소 12개 배열
	int* pump_recipe = ct.get_pump_recipe(); // 원소 9개 배열
	String ct_name = ct.get_name();
	char* name;
	ct_name.toCharArray(name, ct_name.length() + 1);
	int* ct_color = ct.get_cocktail_color(); // 원소 3개 배열
	TechniqueMethod method = ct.get_technique();

	// 만들기 전, OLED로 칵테일 이름을 표시하고 Led로 칵테일 고유 불빛을 비춤
	oled.display_right(name);
	ledpanel.color(ct_color);
	ledstrip1.color(ct_color);
	ledstrip2.color(ct_color);
	delay(5000); // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 만들기 전 기다리는 시간

	// 전체 양이 얼마나 되는지 체크 (oled 표시용)
	int total_amount = 15;
	int now_amount = 0;

	for (int i = 0; i < 12; i++) {
		total_amount += disp_recipe[i];
	}
	for (int i = 0; i < 9; i++) {
		total_amount += pump_recipe[i];
	} // 스터나 아이스와 관련하여 코드 수정될 수 있음 **************************

	
	//얼음은그냥 다 넣는걸로!?
	plate.moveto(5, 6); // 얼음 받는 위치 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	Technique t;
	t.add_ice(ct.get_glass_info());
	

	// 잔량 체크 코드를 지우고 전체 양을 계산하는 코드를 넣음. OLED에 진행도를 표시하기 위함
	// 디스펜서를 사용하는 재료부터 시작
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			DispenserMaterial material("temp_disp_mtrl", 0, 0, 0, 0, 0);
			EEPROM.get(mtrl_size * i, material);
			String mtrl_name = material.get_name();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, mtrl_name);
			total_amount += disp_recipe[i];

			// Led 색깔 재료 고유의 색으로 바꾸기
			ledpanel.color(material.get_rgb());
			ledstrip1.color(material.get_rgb());
			ledstrip2.color(material.get_rgb());
			delay(1000); // 색 바꾸고 1초동안 기다려 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

			// 좌표 설정하고, plate 움직이기
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.moveto(coord);
			delay(1000); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2

			// 좌표로 이동했으면 액츄에이터 작동 (해당 레시피의 양에 해당하는 시간만큼)
			plate.push_dispenser(disp_recipe[i]);

			delay(1000); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	// 디스펜서 다음 펌프를 사용하는 재료 담기
	for (int i = 0; i < 9; i++) {
		if (pump_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			PumpMaterial material("temp_pump_mtrl", 0, 0, 0, 0, 0);
			EEPROM.get(eeprom_pump_start_adrs + mtrl_size * i, material);
			String mtrl_name = material.get_name();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, mtrl_name);
			total_amount += pump_recipe[i];

			// Led 색깔 재료 고유의 색으로 바꾸기
			ledpanel.color(material.get_rgb());
			ledstrip1.color(material.get_rgb());
			ledstrip2.color(material.get_rgb());
			delay(1000); // 색 바꾸고 1초동안 기다려 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22

			// 좌표 설정하고, plate 움직이기
			coord.set(material.get_pos_x(), material.get_pos_y());
			plate.moveto(coord);
			delay(1000); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

			// 좌표로 이동했으면 !펌프! 작동 (해당 레시피의 양에 해당하는 시간만큼)
			pump_instance.work_pump(i + 1, pump_recipe[i]);
			delay(1000); //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	oled.display_progress(now_amount, total_amount, name);
	delay(2000); // 전부 다 따르고 스터 또는 빌드 하기 전에 기다림 @@@@@@@@@@@@@@@@@@@@@@@@@@2

	// 주조 기법에 따라 주조하기
	ledpanel.color(ct_color); // 해당 칵테일의 고유 색 표현
	ledstrip1.color(ct_color);
	ledstrip2.color(ct_color);

	// 테크닉 인스턴스에다가 위에서 선언해준 method를 전달해 그 명령 수행
	t.f(method);
	oled.display_progress(now_amount, total_amount, name);
	delay(2000); // 완성 하고 complete 표시하기 전 까지 잠시 기다림 @@@@@@@@@@@@@@@@@@@@@@@@@@@2

	// 칵테일 완성!!
	oled.display_complete();    // OLED에 완료했다고 표시
	plate.move_to_initial_position();    // move to init pos

	return 1; // 리턴 코드 1: 칵테일 완성
}


void Operation::emergency_stop()
{
	Oled o;
	o.display_center("emergency stop!");

	exit(1); // 에러 코드 1: 무효한 블루투스 입력 값
}


#endif