#include "Node.h"

Node::Node(char x)
{
	data = x;
	next = NULL;
}
void Node::setData(char x)
{
	data = x;
}
char Node::getData()const
{
	return data;
}
void Node::setNextPtr(Node*n)
{
	next = n;
}
Node*Node::getNextPtr()const
{
	return next;
}


Node::~Node()
{
}
