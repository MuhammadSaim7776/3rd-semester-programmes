#pragma once
#include"point.h"
class Node
{
private:
	point data;
	Node*next;
public:
	Node(int x,int y);
	void set_X(int x);
	void set_Y(int y);
	void set_data(int x, int y);
	void set_Next(Node*);
	int get_X();
	int get_Y(); 
	Node* get_next();
	~Node();
	friend class snake;
};

