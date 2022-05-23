#include<stdio.h>   // c 기본 라이브러리, 
#include<Windows.h> // window 콘솔에 그림을 그릴 수 있는 라이브러리
#include<conio.h>   // 키보드 값을 받아오는 라이브러리
#include<time.h>    // 현재 시간을 받아와 기록하기 위한 라이브러리. 
#include <iostream> // c++ cout, cin 사용하기 위한 라이브러리, 
#include <random>   // 랜덤값을 받아오기 위한 라이브러리 
#include <cmath>    // 값 가공할건데, 주로 실수값을 정수값으로 변환해주기 위해 많이 사용할 예정임. 
#include <vector>   // 배열 쓸거임. 근데 정적배열말고 동적배열써서 사용자 값에 따라 크기 다르게 할당할거임, 물론 엄청 큰값을 받을게 아니라 정적 배열로 선언해도 되지만, 혹여나 규모가 큰 프로그램에 사용될 경우, 메모리 자원을 아낄 수 있기 때문에 inclue array 대신 vector를 선택함. ㅇㅇ 

using namespace std;

int GetKeyDown(); // 키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int Select_Menu();  // 초반 메뉴 선택 화면. 
void Start_Program_Menu(bool wrong_num);   // 1번 메뉴, 프로그램 시작
void Random_Test_Menu(bool print_error); // 2번 메뉴, 테스트 프로그램 시작. 
void SetConsoleView();  // 콘솔창 크기 조정
void GotoXY(int X, int Y);   // 좌표값 이동함수. 
int GetKeyDown();   // 키보드값 받아오는 함수. 
void Make_new_seat(int x, int y);    // 새 좌석 만들기 1-1번메뉴
void Call_made_seat(int x, int y);   // 기존 좌석 불러오기 1-2번 메뉴



int main(void){
    SetConsoleView();   // 콘솔 사이즈 지정. 
    int num;

    while(true){
        num = Select_Menu();

        if(num == 1) Start_Program_Menu(false);
        if(num == 2) Random_Test_Menu(false); 
        if(num == 3) break;
        else continue;
    }
    return 0;
}


int Select_Menu()
{
    int option;
    system("cls");
    int x = 18;
    int y = 2;
    GotoXY(x, y);
    printf("==================================");
    GotoXY(x, y + 1);
    printf("========== * M E N U * ===========");
    GotoXY(x, y + 2);    
    printf("==================================");
    GotoXY(x, y + 4);
    printf("   1. 도서관 자리 체크");
    GotoXY(x, y + 6);
    printf("   2. 랜덤으로 테스트하기");
    GotoXY(x, y + 8);
    printf("   3. 프로그램 종료");

    GotoXY(x, y + 10);

    cin >> option;
    return option;

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

void Start_Program_Menu(bool wrong_num)
{
    int Option=0;
    system("cls");
    int x = 18;
    int y = 2; 
    GotoXY(x, y);
    printf("================================");
    GotoXY(x, y + 1);
    printf("=========* 좌석 설정 *==========");
    GotoXY(x, y + 2);
    printf("================================");
    GotoXY(x, y+5);
    printf("    1. 새, 좌석 만들기 ");
    GotoXY(x, y+7);
    printf("    2. 저장된 좌석  불러오기");
    if(wrong_num){
    GotoXY(x, y+9);
    printf("please select another num");
    }

    cin >> Option;

    switch(Option){
        case 1:
            Make_new_seat(x, y);    // 새 좌석 만들기
            break;
        case 2:
            Call_made_seat(x, y);   // 기존 좌석 불러오기
            break;
        default:
            wrong_num = true;
            Start_Program_Menu(true);
    }
    wrong_num = false;
    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

void Make_new_seat(int x, int y){
    system("cls");
    GotoXY(x, y+3);
    printf("새 좌석 생성하는 프로그램은 받는 값은 뭔값으로 할거임? ");

    GotoXY(x, y+5);
    printf("응애 이건 너가 만들어 화이팅");

    printf("\n\n\n\n\n\n\n\n\n");
}
void Call_made_seat(int x, int y){
    system("cls");
    GotoXY(x, y+3);
    printf("기존 좌석 불러오기 이거는 파일 생성 write 함수 쓰면 됨 ㅅㄱ");

    GotoXY(x, y+5);
    printf(" ㅋㅋ 졸작 화이팅 >< ");
    GotoXY(x+5, y+8);
    printf(" ^오^ b ");


    printf("\n\n\n\n\n\n\n\n\n");
}
void Random_Test_Menu(bool print_error)   // 에러 표시 메세지 출력. 
{
    random_device rd;   // random값을 얻기위한 random_device값을 rd로 사용할거임.
    mt19937 gen(rd()); // random_device에서 난수 생성 엔진 초기화 -> 의사난수값 말고 진짜 난수 사용하기 위해.
    mt19937 gen1(rd()); 
    mt19937 gen2(rd());

    int Max_Seat, Min_Seat = 0;   // 최대 최소 좌석수 받아올거임. 
    int ran_row, ran_col =0;    // 랜덤으로 생성할 좌석, 행, 열 저장할거임. 
    system("cls");
    int x = 18;
    int y = 2; 
    if(print_error){    // 입력에 오류가 생긴 경우,  
        GotoXY(x, y+2);
        printf("최대값혹은  최소값을 다시 입력해 주세요 :)");
    }
    GotoXY(x, y);
    printf("====================================");
    GotoXY(x, y + 1);
    printf("========== 랜덤 좌석 설정 ==========");
    GotoXY(x, y + 2);
    printf("====================================");

    GotoXY(x, y+4);
    printf("        [MAX = 150]");
    GotoXY(x, y+5);
    printf("    1. 최대 좌석 수 설정 : ");
    cin >> Max_Seat;

    GotoXY(x, y+7);
    printf("        [MIN = 1]");
    GotoXY(x, y +8); 
    printf("    2. 최소 좌석 수      : ");
    cin >> Min_Seat;

    if(Max_Seat<Min_Seat || Max_Seat>150 || Min_Seat<1){
        Random_Test_Menu(true);     // 최소값, 최댓값이 정상적으로 입력되지 않은경우, 다시 값을 받아오고 에러메시지 출력
        // 재귀 호출 사용. 
    }
    else{   // 최대값, 최소값이 정상적으로 입력된 경우, 
        // start test program()
        system("cls");

        // 받아온 최대, 최소 좌석수 값으로 난수 생성. -> 랜덤 좌석 만들기 드가자~
        uniform_int_distribution<int> dis(Min_Seat, Max_Seat);
        int random_value = dis(gen);

        // 사용 불가능 좌석 랜덤하게 뽑기
        uniform_int_distribution<int> dis1(0, random_value);
        int cant_Seat_total = dis1(gen1); // 사용 불가능한 좌석 개수. 

        int cant_Seat_num;  // 사용 불가능한 좌석 번호. 

        vector<int> Cant_arr(random_value +2);    // 사용 불가능한 좌석 체크용 array
        for(int i=0; i<cant_Seat_total; i++){   // 사용 불가능한 좌석 개수만큼 난수 생성, 
            uniform_int_distribution<int> dis2(1, random_value+1);   // 좌석번호 1부터, 마지막 번호까지 랜덤으로 
            cant_Seat_num = dis2(gen2);   //  사용 불가능한 좌석 번호를 뽑음.

            // 만약 전에 뽑은 좌석 번호일 경우(중복 방지) 다시 뽑기
            if(Cant_arr.at(cant_Seat_num) != 0) {
                i--;
                continue;
            } 
            Cant_arr.at(cant_Seat_num)++;
        }   

        // display 상단 가운데 표기
        GotoXY(x+15, y);
        printf("[랜덤 자리 %d개 생성 완료]", random_value);

        // display 왼쪽 상단에 표기
        GotoXY(x-16, y+2);
        cout << "사용 가능 좌석   : (" << random_value<<"/" << random_value - cant_Seat_total<<")개"; 
        GotoXY(x-16, y+3);
        cout << "사용 가능 좌석   : (" << random_value<<"/" << cant_Seat_total<<")개"; 

        // display 오른쪽 상단에 표기
        ran_row = round(sqrt(random_value));
        ran_col = ran_row -1;
        GotoXY(x+45, y+2);
        cout << "full rows : " << ran_row << std::endl;
        GotoXY(x+45, y+3);
        cout << "full cols : " << ran_col << std::endl;



        int cnt=0, add=5;
        // 좌석 표기
        for(int c=0; c<ran_col; c++){
            for(int r=0; r<ran_row*add; r+=add){
                cnt++;
                GotoXY(x+5+r, y+c+7);
                Cant_arr.at(cnt)==1? printf("[%d]", cnt) : printf("[  ]");
                random_value--;
            }

            if(c == ran_col -1 && random_value != 0){// 만일 마지막 열까지 다 돌고, random value 값이 아직 남아있는 경우, 
                // 즉 모든 좌석이 display 되지 않은 경우, 남은 좌석 prinf해줌
                for(int r=0; r<random_value*add; r+=add){
                    cnt++;
                    GotoXY(x+5+r, y+c+8);
                    Cant_arr.at(cnt)==1? printf("[%d]", cnt) : printf("[  ]");
                }
            }
        }
        // 좌석 표기 끝
    }

    // display 중앙 하단에 출력. 
    GotoXY(x+5, y+22);
    printf("사용 가능 : [n] / 사용 불가능 [ ]");
    GotoXY(x+45, y+23);
    printf("아무키 입력시 메뉴로 이동");
   

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

void SetConsoleView()
{
    system("mode con:cols=100 lines=30");
    system("library auto check program");
}

void GotoXY(int X, int Y)   // 좌표값 이동함수. 
{
    COORD Pos;
    Pos.X = X;
    Pos.Y = Y;
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
