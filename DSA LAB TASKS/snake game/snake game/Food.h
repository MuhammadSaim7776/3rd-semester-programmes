#pragma once
#include"point.h"
#include <cstdlib>
#define height 25
#define width 50
class Food
{
private:
	point position;
public:
	Food();
	void gen_food();
	point get_foodPossition();
	int get_foodX();
	int get_foodY();
	~Food();
};

