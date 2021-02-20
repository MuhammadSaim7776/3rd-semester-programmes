#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	int i, j, s;
	cout << "enter the no of rows";
	cin >> s;
	for (i = 0; i < s; i++)
	{
		if (i % 2 == 1)
		{
			cout << " ";
		}
		for (j = 0; j < s; j++)
		{
			cout << "*";
			cout << " ";
		}
		cout << endl;
	}
	_getch();
}