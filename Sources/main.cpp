#include<cstdio>   // c 기본 라이브러리, 
#include<Windows.h> // window 콘솔에 그림을 그릴 수 있는 라이브러리
#include<conio.h>   // 키보드 값을 받아오는 라이브러리
#include <iostream> // c++ cout, cin 사용하기 위한 라이브러리, 
#include <random>   // 랜덤값을 받아오기 위한 라이브러리 
#include <cmath>    // 값 가공할건데, 주로 실수값을 정수값으로 변환해주기 위해 많이 사용할 예정임. 
#include <vector>   // 배열 쓸거임. 근데 정적배열말고 동적배열써서 사용자 값에 따라 크기 다르게 할당할거임, 물론 엄청 큰값을 받을게 아니라 정적 배열로 선언해도 되지만, 혹여나 규모가 큰 프로그램에 사용될 경우, 메모리 자원을 아낄 수 있기 때문에 inclue array 대신 vector를 선택함. ㅇㅇ 
#include <string>	// string 사용할거임
#include <windows.h>	// console 창 조작할거임. 

using namespace std;

int GetKeyDown(); // 키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int Select_Menu();  // 초반 메뉴 선택 화면. 
void Start_Program_Menu(bool wrong_num);   // 1번 메뉴, 프로그램 시작
void Random_Test_Menu(const bool error_check); // 2번 메뉴, 테스트 프로그램 시작. 
void GotoXY(int move_x, int move_y);   // 좌표값 이동함수. 
void Make_new_seat();    // 새 좌석 만들기 1-1번메뉴
void Call_made_seat();   // 기존 좌석 불러오기 1-2번 메뉴
void print_standard_menu(string menu_str);  // 메뉴 출력 함수. 


const int x = 18, y = 2;    // 기준 좌표값 설정. 
#define PRN_N printf("\n\n\n\n\n\n\n\n\n")  // 자주 사용할 print문 define

void SetConsoleView()	// 콘솔 사이즈 지정. 
{
	system("mode con:cols=100 lines=35");
	system("library auto check program");
}

int main(void) {
	SetConsoleView();   // 콘솔 사이즈 지정. 
	int num = 0;
	while (true) {
		num = Select_Menu();

		if (num == 1) Start_Program_Menu(false);
		if (num == 2) Random_Test_Menu(false);
		if (num == 3) break;
	}
	return 0;
}


int Select_Menu()
{
	int option;
	system("cls");
	print_standard_menu("M E N U");
	GotoXY(x, y + 4);
	printf("   1.  Check to library seats");
	GotoXY(x, y + 6);
	printf("   2.  Test program with random values");
	GotoXY(x, y + 8);
	printf("   3.  Quit the program");

	GotoXY(x, y + 10);

	cin >> option;
	return option;

	PRN_N;
	system("pause");
}

void print_standard_menu(string menu_str)
{
	GotoXY(x, y);
	printf("================================");
	GotoXY(x, y + 1);
	cout << "	  " << menu_str << endl;
	GotoXY(x, y + 2);
	printf("================================");
}
void Start_Program_Menu(bool wrong_num)
{
	int Option = 0;
	system("cls");
	print_standard_menu("setting library seats");
	GotoXY(x, y + 5);
	printf("    1. make new seats ");   // 새로운 좌석 만들기. 
	GotoXY(x, y + 7);
	printf("    2. call made seats settings ");     // 이미 만든 파일 불러오기

	GotoXY(x, y + 9);// 번호 잘못 선택했을 때 출력하고 다시 재귀호출할거임 ㅇㅇ
	wrong_num ? printf("    please check the input number ") : printf(" ");  // 번호 다시 입력하세요~~

	cin >> Option;
	switch (Option) {
	case 1:
		Make_new_seat();    // 새 좌석 만들기
		break;
	case 2:
		Call_made_seat();   // 기존 좌석 불러오기
		break;
	default:
		wrong_num = true;
		Start_Program_Menu(true);
	}
	PRN_N;
	system("pause");
}

void Make_new_seat() {   // 새로운 자리 생성 함수. 
	system("cls");
	GotoXY(x, y + 3);
	printf(" init the new seat setting !  ");   // 새로운 자리 생성하는 함수는 너가 알아서 짜시고 ㅇㅇ
	PRN_N;
}
void Call_made_seat() {  // 기존 자리 불러오는 함수. 
	system("cls");
	GotoXY(x, y + 3);
	printf(" call back the made setting files  ");  // 기존에 만들어둔 파일 저장하는건 write, 불러오는 것도 file write or read 함수 검색해서 하면 됨 ㅇㅇ
	GotoXY(x + 5, y + 8);
	printf(" ^_^ b ");
	PRN_N;
}

void Random_Test_Menu(const bool error_check)   // 에러 표시 메세지 출력. 
{
	random_device rd;   // random값을 얻기위한 random_device값을 rd로 사용할거임.
	mt19937 gen_seats_total(rd()); // random_device에서 난수 생성 엔진 초기화 -> 의사난수값 말고 진짜 난수 사용하기 위해.
	mt19937 gen_cant_total(rd());
	mt19937 gen_cant_num(rd());

	int max_seat, min_seat = 0;   // 최대 최소 좌석수 받아올거임. 
	system("cls");
	if (error_check) {    // 입력에 오류가 생긴 경우,  
		GotoXY(x, y + 10);
		printf(" plz input again MAX or MIN values :)");
	}
	print_standard_menu("setting random seats");
	GotoXY(x, y + 4);
	printf("        [MAX = 150]");
	GotoXY(x, y + 5);
	printf("    1. input MAX values: ");
	cin >> max_seat;

	GotoXY(x, y + 7);
	printf("        [MIN = 1]");
	GotoXY(x, y + 8);
	printf("    2. input MIN values: ");
	cin >> min_seat;

	if (max_seat < min_seat || max_seat>150 || min_seat < 1) {
		Random_Test_Menu(true);     // 최소값, 최댓값이 정상적으로 입력되지 않은경우, 다시 값을 받아오고 에러메시지 출력
	}
	// 최대값, 최소값이 정상적으로 입력된 경우, 
	system("cls");

	uniform_int_distribution<int> dis_seats_total(min_seat, max_seat); // 받아온 최대, 최소 좌석수 값으로 난수 생성. -> 랜덤 좌석 만들기 드가자~
	int random_value = dis_seats_total(gen_seats_total);

	uniform_int_distribution<int> dis_cant_total(0, random_value); // 사용 불가능 좌석 랜덤하게 뽑기
	int cant_seat_total = dis_cant_total(gen_cant_total); // 사용 불가능한 좌석 개수. 

	vector<int> cant_arr(random_value + 2);    // 사용 불가능한 좌석 체크용 array
	for (int i = 0; i < cant_seat_total; i++) {   // 사용 불가능한 좌석 개수만큼 난수 생성, 
		uniform_int_distribution<int> dis_cant_num(1, random_value + 1);   // 좌석번호 1부터, 마지막 번호까지 랜덤으로 
		const int cant_seat_num = dis_cant_num(gen_cant_num);   //  사용 불가능한 좌석 번호를 뽑음.

			// 만약 전에 뽑은 좌석 번호일 경우(중복 방지) 다시 뽑기
		cant_arr.at(cant_seat_num) ? i-- : cant_arr.at(cant_seat_num)++;
	}

	GotoXY(x + 15, y); // display 상단 가운데 표기
	printf("[ made successful!! / total seats: %d ]", random_value);

	GotoXY(x - 16, y + 2); // display 왼쪽 상단에 표기
	cout << " usable seats: (" << random_value << "/" << random_value - cant_seat_total << ")";
	GotoXY(x - 16, y + 3);
	cout << " unusable seats: (" << random_value << "/" << cant_seat_total << ")";

	const int ran_row = round(sqrt(random_value)); // display 오른쪽 상단에 표기
	const int ran_col = ran_row - 1;
	GotoXY(x + 45, y + 2);
	cout << "full rows : " << ran_row << std::endl;
	GotoXY(x + 45, y + 3);
	cout << "full cols : " << ran_col << std::endl;

	int cnt = 0;
	for (int c = 0; c < ran_col; c++) {
		for (int r = 0; r < ran_row * 5; r += 5) {
			cnt++;
			GotoXY(x + 5 + r, y + c + 7);
			cant_arr.at(cnt) == 1 ? printf("[%d]", cnt) : printf("[  ]");
			random_value--;
		}

		if (c == ran_col - 1 && random_value != 0) {// 만일 마지막 열까지 다 돌고, random value 값이 아직 남아있는 경우, 즉 모든 좌석이 display 되지 않은 경우, 남은 좌석 print 해줌
			for (int r = 0; r < random_value * 5; r += 5) {
				cnt++;
				GotoXY(x + 5 + r, y + c + 8);
				cant_arr.at(cnt) == 1 ? printf("[%d]", cnt) : printf("[  ]");
			}
		}
	}
	// display 중앙 하단에 출력. 
	GotoXY(x + 5, y + 22);
	printf("usable : [n] / unusable : [ ]");
	GotoXY(x + 45, y + 23);
	printf("input any key go to menu");
	PRN_N;
	system("pause");
}


void GotoXY(int move_x, int move_y)   // 좌표값 이동함수. 
{
	COORD Pos;
	Pos.X = move_x;
	Pos.Y = move_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)  // 키보드 입력이 들어온 경우, (0이 아닌 경우)
	{
		return _getch();    // 숫자 하나 입력받음. 
	}
	return 0;
}
