#include "BNode.h"


BNode::BNode(char data)
{
	this->data = data;
	leftchild = NULL;
	rightchild = NULL;
	parent = NULL;
}
void BNode::set_data(char data)
{
	this->data = data;
}
char BNode::get_data()const
{
	return data;
}
BNode::~BNode()
{
}
