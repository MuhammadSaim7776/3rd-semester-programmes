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
void point::Move_Up(int v)
{
	y-=v;
}
void point::Move_Down(int v)
{
	y+=v;
}
void point::Move_Right(int v)
{
	x+=v;
}
void point::Move_Left(int v)
{
	x-=v;
}
void point::draw()
{
	cout << "*";
}
void point::erase()
{
	cout << " ";
}

point::~point()
{
}
