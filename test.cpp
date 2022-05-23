#include<stdio.h>
#include<Windows.h> // window 콘솔에 그림을 그릴 수 있는 라이브러리
#include<conio.h>   // 키보드 값을 받아오는 라이브러리
#include<time.h>    // 현재 시간을 받아와 기록하기 위한 라이브러리. 
#include <iostream>

using namespace std;

int GetKeyDown(); // 키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
void Select_Menu();  // 초반 메뉴 선택 화면. 

void SetConsoleView()
{
    system("mode con:cols=100 lines=25");
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

int main(void){
    SetConsoleView();   // 콘솔 사이즈 지정. 
    int num;

    while(true){
        Select_Menu();
    }

    return 0;
}


void Select_Menu()
{
    int num=0;
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======* * M E N U * *======");
    GotoXY(x, y + 2);    
    printf("===========================");
    GotoXY(x, y + 4);
    printf("    1. 도서관 자리 체크");
    GotoXY(x, y + 5);
    printf("    2. 랜덤으로 테스트하기");
    GotoXY(x, y + 8);

    GotoXY(x, y + 10);

    cin >> num;
    if(num == 1) cout<< "프로그램이 시작됩니다. "<<endl;
    if(num == 2) cout<< "테스트가 시작됩니다. "<<endl;
    
    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}
