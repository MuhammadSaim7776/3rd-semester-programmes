#include "Node.h"

Node::Node(string x)
{
	data = x;
	next = NULL;
}
void Node::setData(string x)
{
	data = x;
}
string Node::getData()const
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
