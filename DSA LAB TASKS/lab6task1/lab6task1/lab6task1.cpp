#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	char ascii;
	ascii = 1;
	while (ascii >= 0 && ascii <= 127)
	{
		if (ascii % 16 == 0)
		{
			cout << endl;
		}
	
			cout << ascii;
		ascii++;

	}
	_getch();
}