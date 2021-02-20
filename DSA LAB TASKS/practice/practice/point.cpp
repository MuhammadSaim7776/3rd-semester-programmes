#include "point.h"


point::point()
{
	x = y = 0;
}
point::point(int x,int y)
{
	set_values(x, y);
}
void point::set_values(int x, int y)
{
	set_X(x);
	set_Y(y);
}
void point::set_X(int x)
{
	this->x = x;
}
void point::set_Y(int y)
{
	this->y = y;
}
int point::get_X()
{
	return x;
}
int point::get_Y()
{
	return y;
}
void point::move_Up()
{
	y--;
}
void point::Move_Down()
{
	y++;
}
void point::Move_Right()
{
	x++;
}
void point::Move_Left()
{
	x--;
}
void point::draw()
{
	gotoxy(x, y);
	cout << "*";
}
void point::erase()
{
	cout << " ";
}
//void point::gotoxy(int x, int y)
//{
//	Position.X = x; // Locates column
//	Position.Y = y; // Locates Row
//	SetConsoleCursorPosition(console, Position); // Sets position for next thing to be printed 
//}
point::~point()
{
}
