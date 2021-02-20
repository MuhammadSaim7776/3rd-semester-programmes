#include<iostream>
#include<conio.h>
using namespace std;
void moveTower(int disks, char source, char destination, char temporary)
{
	if (disks == 1)
	{
		cout << "Move disk 1 from Pole " << source << " to pole " << destination << endl;
	}
	else
	{
		moveTower(disks - 1, source, temporary, destination);
		cout << "Move disk "<<disks<<" from " << source << " to " << destination << endl;
		moveTower(disks - 1, temporary, destination, source);
	}
}
void main()
{
	moveTower(3, 'A', 'C', 'B');
	_getch();

}