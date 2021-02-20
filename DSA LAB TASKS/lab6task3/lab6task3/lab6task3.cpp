#include<iostream>
#include<conio.h>
using namespace std;
void main()
{

	char i, j;
	int N;
	cout << "enter number of column or rows";
	cin >> N;
	for (i = N; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	_getch();
}