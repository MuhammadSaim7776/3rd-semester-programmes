#pragma once
#include<iostream>
#include<conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
class point
{
private:
	int x;
	int y;
public:
	point();
	point(int x, int y);
	void move_Up();
	void Move_Down();
	void Move_Right();
	void Move_Left();
	int get_X();
	int get_Y();
	void set_X(int x);
	void set_Y(int y);
	void set_values(int x, int y);
	void draw();
	void erase();
	~point();
};


