/*
 Name:		Project_Cocktail_Machine.ino
 Created:	2020-07-15 오전 2:20:54
 Author:	USER
*/


// ========= user-installed headers ==========


// ========= user-defined headers ============
#include "Operation.h"


// ============ global variables =============
Operation ctrl;

//new ver
extern DispenserMaterial disp_mtrl_arr[12];
extern PumpMaterial pump_mtrl_arr[9];
extern Cocktail cocktail_arr[18];
extern Adafruit_NeoPixel ledpanel;
extern Adafruit_NeoPixel ledstrip1;
extern Adafruit_NeoPixel ledstrip2;


/*
Adafruit_NeoPixel iledpanel = Adafruit_NeoPixel(256, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel iledstrip1 = Adafruit_NeoPixel(55, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel iledstrip2 = Adafruit_NeoPixel(55, 4, NEO_GRB + NEO_KHZ800);*/

// ===================== setup & loop =====================
void setup() 
{
	//Oled oled_instance;
	//oled_instance.display_preparing();

	Serial.begin(9600);

	  Serial.println("\n\n= start debugging...");

	ctrl.preset_dispenser_materials();
	ctrl.preset_pump_materials();
	ctrl.preset_cocktail_recipes();

	ctrl.initialize();
}


void loop() 
{
	/*
	// LED 인스턴스 생성
	iledpanel.begin();
	iledstrip1.begin();
	iledstrip2.begin();

	iledpanel.clear();
	iledpanel.setBrightness(20);
	iledpanel.show();

	iledstrip1.clear();
	iledstrip1.setBrightness(50);
	iledstrip1.show();

	iledstrip2.clear();
	iledstrip2.setBrightness(50);
	iledstrip2.show();*/


	int flag = 1;  // 1이면 명령 기다림, 0이면 명령 탈출
	int res_index = -1; // bluetooth_connect의 리턴 값

	// 전원 연결이 되면, oled는 로고를 출력해 입력을 기다리고 있음을 나타냄
	Oled oled;
	oled.display_center("Welcome!");
	delay(2000); 
	oled.display_center("waiting");
	
	/*
	for (int i = 0; i < 256; i++) {
		iledpanel.setPixelColor(i, 121, 0, 214);
	}
	iledpanel.show();
		
	for (int i = 0; i < 55; i++) {
		iledstrip1.setPixelColor(i, 121, 0, 214);
	}
	iledstrip1.show();

	for (int i = 0; i < 55; i++) {
		iledstrip2.setPixelColor(i, 121, 0, 214);
	}
	iledstrip2.show();*/

	while (flag) { // flag 1: 명령 기다림 | flag 0: 명령 받아 while 탈출
	// LED 레인보우를 동시에 표현하기 위한 코드
		int time_marker = millis();

		res_index = ctrl.bluetooth_connect();
		// res_index notation:
		// 0~15: 미리 정의해놓은 칵테일
		// 16: 시그니쳐
		// 17: 나만의 레시피 or 랜덤 레시피
		// 18: 에러 | -1: 응답없음
		if (res_index == 18) ctrl.emergency_stop();
		else if (res_index >= 0 && res_index <= 17) {
			flag = 0;
		}
		// 보통 명령 없을 때, millis() 차이는 몇초?

		Serial.println(res_index);

	} // end of while

	/*
	// 칵테일 만들기
	ctrl.make_cocktail(res_index);
	delay(2000);
	*/

	//칵테일 만들기(new ver)
	Cocktail ct = cocktail_arr[res_index];

	// 컨트롤을 위한 인스턴스 생성;
	Oled oled;
	Plate plate;
	Pump pump_instance;

	// 사용하기 쉽게 칵테일 정보들을 미리 선언해준다.
	int* disp_recipe = ct.get_disp_recipe(); // 원소 12개 배열
	int* pump_recipe = ct.get_pump_recipe(); // 원소 9개 배열
	String ct_name = ct.get_name();
	char* name;
	name = ct_name.c_str();
	int* ct_color = ct.get_cocktail_color(); // 원소 3개 배열
	TechniqueMethod method = ct.get_technique();

	// 만들기 전, OLED로 칵테일 이름을 표시하고 Led로 칵테일 고유 불빛을 비춤
	oled.display_center(name);

	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip2.show();


	delay(3000);

	// 전체 양이 얼마나 되는지 체크 (oled 표시용)
	int total_amount = 0;
	int now_amount = 0;

	for (int i = 0; i < 12; i++) {
		total_amount += disp_recipe[i];
	}
	for (int i = 0; i < 9; i++) {
		total_amount += pump_recipe[i];
	} // total amount 계산 완료

	oled.display_center("ice");
	plate.moveto(190, 1200);
	Technique t;
	t.add_ice(ct.get_glass_info());


	// 잔량 체크 코드를 지우고 전체 양을 계산하는 코드를 넣음. OLED에 진행도를 표시하기 위함
	// 디스펜서를 사용하는 재료부터 시작
	for (int i = 0; i < 12; i++) {
		if (disp_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			DispenserMaterial material = disp_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();
			int* mtrl_color = material.get_rgb();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += disp_recipe[i];

			for (int i = 0; i < 256; i++) {
				ledpanel.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledpanel.show();

			for (int i = 0; i < 55; i++) {
				ledstrip1.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip1.show();

			for (int i = 0; i < 55; i++) {
				ledstrip2.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip2.show();

			// Led 색깔 재료 고유의 색으로 바꾸기

			// 좌표 설정하고, plate 움직이기
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// 좌표로 이동했으면 액츄에이터 작동 (해당 레시피의 양에 해당하는 시간만큼)
			plate.push_dispenser(disp_recipe[i]);

			delay(100);
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	// 디스펜서 다음 펌프를 사용하는 재료 담기
	for (int i = 0; i < 9; i++) {
		if (pump_recipe[i]) { // 만약 해당 재료의 레시피가 0이면 그 재료는 무시함
		   // 쉬운 코딩을 위해 해당 레시피의 인스턴스 선언
			PumpMaterial material = pump_mtrl_arr[i];
			String mtrl_name = material.get_name();
			char* c_mtrl_name = mtrl_name.c_str();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += pump_recipe[i];

			int* mtrl_color = material.get_rgb();

			// OLED 표시
			oled.display_progress(now_amount, total_amount, c_mtrl_name);
			now_amount += disp_recipe[i];

			for (int i = 0; i < 256; i++) {
				ledpanel.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledpanel.show();

			for (int i = 0; i < 55; i++) {
				ledstrip1.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip1.show();

			for (int i = 0; i < 55; i++) {
				ledstrip2.setPixelColor(i, mtrl_color[0], mtrl_color[1], mtrl_color[2]);
			}
			ledstrip2.show();

			// Led 색깔 재료 고유의 색으로 바꾸기

			// 좌표 설정하고, plate 움직이기
			plate.moveto(material.get_pos_x(), material.get_pos_y());
			delay(100);

			// 좌표로 이동했으면 !펌프! 작동 (해당 레시피의 양에 해당하는 시간만큼)
			pump_instance.work_pump(i + 1, pump_recipe[i]); //1~9
			delay(100);
		} // 재료 하나의 루프가 끝났으면, 다시 다른 재료로 이 루프를 또 실행
	}

	oled.display_progress(now_amount, total_amount, name);
	delay(1000);;

	for (int i = 0; i < 256; i++) {
		ledpanel.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledpanel.show();

	for (int i = 0; i < 55; i++) {
		ledstrip1.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip1.show();

	for (int i = 0; i < 55; i++) {
		ledstrip2.setPixelColor(i, ct_color[0], ct_color[1], ct_color[2]);
	}
	ledstrip2.show();


	// 테크닉 인스턴스에다가 위에서 선언해준 method를 전달해 그 명령 수행
	t.f(ct);
	// 칵테일 완성!!
	oled.display_complete();    // OLED에 완료했다고 표시
	// ********* 무지개 빙글빙글 (스트립만)
	rainbow(10);
	rainbow(10);
	rainbow(10);

	return 1; // 리턴 코드 1: 칵테일 완성

	

}

