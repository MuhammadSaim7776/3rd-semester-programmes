#include "Node.h"

Node::Node()
{
	set_Data(-1);
	set_Next(NULL);
}
Node::Node(int Data)
{
	set_Data(Data);
	set_Next(NULL);
}
void Node::set_Data(int Data)
{
	this->Data = Data;
}
void Node::set_Next(Node*Next)
{
	this->Next = Next;
}
int Node::get_Data()
{
	return Data;
}
Node* Node::get_Next()
{
	return Next;
}

Node::~Node()
{
}
