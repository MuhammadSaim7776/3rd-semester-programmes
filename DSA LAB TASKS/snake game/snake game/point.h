#pragma once
#include<iostream>

using namespace std;
class point
{
private:
	int x;
	int y;
public:
	point();
	point(int x, int y);
	void Move_Up(int);
	void Move_Down(int);
	void Move_Right(int);
	void Move_Left(int);
	int get_X();
	int get_Y();
	void set_X(int x);
	void set_Y(int y);
	void set_values(int x, int y);
	void draw();
	void erase();
	~point();
};


