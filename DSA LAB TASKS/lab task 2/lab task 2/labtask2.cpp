#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int i, j;
	for (i = 1; i <= 7; i++)
	{
		for (j = i; j <=i; j++)
		{
			cout << j;
		}
		cout << endl;
	}
	_getch();
}