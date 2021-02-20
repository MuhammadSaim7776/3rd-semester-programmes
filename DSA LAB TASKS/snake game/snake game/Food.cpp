#include "Food.h"


Food::Food()
{
	
}
void Food::gen_food()
{
	position.set_X((rand() % width-3)+1);
	position.set_Y((rand() % height-3)+1);
}
point Food::get_foodPossition()
{
	return position;
}
int Food::get_foodX()
{
	return position.get_X();
}
int Food::get_foodY()
{
	return position.get_Y();
}


Food::~Food()
{
}
