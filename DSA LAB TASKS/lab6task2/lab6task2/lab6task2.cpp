#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	float y=1, sum = 0;
	while (y >= 1 && y <= 45)
	{
		sum = sum + 1 / y;
		y++;
	}
	cout << sum;
	_getch();

}