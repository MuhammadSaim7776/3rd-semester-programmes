#pragma once
#include"Node.h"
class snake
{
	Node*head;
	point pos;
	int length;
	int velocity;
	char dir;
public:
	snake(Node*,int);
	void increase_Size(Node*);
	int snake_size();
	void decrease_size();
	/*void display_Snake();*/
	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();
	void move();
	point get_position();
	bool eatenFoodOrNot(point);
	void grow();
	bool collision();
	Node*return_head();
	~snake();
	friend class Node;
};

