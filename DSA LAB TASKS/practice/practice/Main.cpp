
#include"point.h"
using namespace std;
//void gotoxy(int x, int y)
//{
//	COORD pos = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}

void main()
{
	point p(5, 20);
	p.draw();
	/*gotoxy(0, 0);
	cout << "*";
	gotoxy(88, 0);
	cout << "*";*/
	_getch();
}