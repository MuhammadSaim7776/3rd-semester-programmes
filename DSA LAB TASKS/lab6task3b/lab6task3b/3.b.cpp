#include<iostream>
#include<conio.h>
using namespace std;
void main()
{

	char i, j, s;
	int N = 10;
	for (i =N; i >= 1; i--)
	{
		for (s = 1; s <= N - i;s++)
		{
			cout << " ";
		}
		for (j = 1; j <= i;j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	_getch();
}