#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
void main()
{ 
	int k = 0;
	int Size = 4;
	int size[4] = { 3, 2, 5, 4 };
	string**ptr = new string*[Size];
	ptr[0] = new string[size[0]];
	ptr[1] = new string[size[1]];
	ptr[2] = new string[size[2]];
	ptr[3] = new string[size[3]];
	ptr[0][0] = "Saim"; ptr[0][1] = "Becholars"; ptr[0][2] = "Masters";
	ptr[1][0] = "TAlha"; ptr[1][1] = "Becholars";
	ptr[2][0] = "Ali"; ptr[2][1] = "Becholars"; ptr[2][2] = "Masters"; ptr[2][3] = "PostGraduate"; ptr[2][4] = "PostDoctrate";
	ptr[3][0] = "Sahil"; ptr[3][1] = "Becholars"; ptr[3][2] = "Masters"; ptr[3][3] = "PostGraduate";
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < size[k]; j++)
		{
			cout << ptr[i][j] << "\t\t";
		}
		k++;
		cout << endl;
	}

	_getch();
}