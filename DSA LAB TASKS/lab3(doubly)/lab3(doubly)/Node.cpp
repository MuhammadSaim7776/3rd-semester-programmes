#include "Node.h"


Node::Node(char Data)
{
	data = Data;
	prevNodePtr = NULL;
	nextNodePtr = NULL;
}
Node *Node::getNextNodeptr()const
{
	return nextNodePtr;
}
void Node::setNextNodePtr(Node* nextNodePtr)
{
	this->nextNodePtr = nextNodePtr;
}
char Node::getdata()const
{
	return data;
}
void Node::setData(char Data)
{
	data = Data;
}
void Node::setprevNodePtr(Node*prevNodePtr)
{
	this->prevNodePtr = prevNodePtr;
}
Node* Node::getPrevNodePtr()const
{
	return prevNodePtr;
}

Node::~Node()
{
}
