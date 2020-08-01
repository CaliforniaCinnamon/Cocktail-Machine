// 
// 수정 필요
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


// 인자로 5(full) ~ 30(empty) 값 받음
void Oled::display_process(int i) 
{
	// 잔 레이아웃을 그리는 코드
	idisplay.drawTriangle(5, 5, 55, 5, 30, 35, WHITE);
	idisplay.drawLine(30, 35, 30, 60, WHITE);
	idisplay.drawLine(15, 60, 45, 60, WHITE);

	// 단계를 표시하기 위해 계산
	int d1 = 1.2 * i - 1;
	int d2 = -1.2 * i + 63;
	idisplay.fillTriangle(i, d1, d2, d1, 30, 35, WHITE);

	// 걍 내가 추가한 코드. 이렇게 쓸거 맞지? 여기다 재료의 이름을 출력?
	char msg[] = "making cocktail...";
	this->display_right(msg);
	idisplay.display();
}

//칵테일 이름 출력(이름 긴 거는 띄어쓰기 기준으로 줄바꿈)
void Oled::display_right(char* msg) {
	idisplay.setTextColor(WHITE);
	idisplay.setTextSize(1);
	char* result = strtok(msg, " ");
	//i 초기 값이랑 증가값 조정 필요
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
	//i 초기 값이랑 증가값 조정 필요
	int i = 30;
	while (result != NULL) {
		idisplay.setCursor(30, i); // display right 함수에서 여기만 바꿈
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
	// 현재 따른 양 now와 전체 양 amount 비율에 따라 스케일링
	int how_much = (0 - 25) * now / amount + 30;
	
	// display_process의 인자; 5 (full) ~ 30 (empty)
	this->display_process(how_much);

	// 진행도 그림 옆에 칵테일 이름을 표시해 준다

	this->display_right(ct_name);

}

// 함수 오버라이딩
void Oled::display_progress(int now, int amount, String ct_name)
{
	char* name;
	ct_name.toCharArray(name, ct_name.length() + 1);
	this->display_progress(now, amount, name);
}

#endif