#include "Node.h"


Node::Node(int x,int y)
{
	data.set_X(x);
	data.set_Y(y);
	next = NULL;
}
void Node::set_data(int x, int y)
{
	data.set_X(x);
	data.set_Y(y);
}
void Node::set_X(int x)
{
	data.set_X(x);
}
void Node::set_Y(int y)
{
	data.set_Y(y);
}
void Node::set_Next(Node*n)
{
	next = n;
}
int Node::get_X()
{
	 return data.get_X();
}
int Node::get_Y()
{
	 return data.get_Y();
}
Node* Node::get_next()
{
	return next;
}

Node::~Node()
{
}
