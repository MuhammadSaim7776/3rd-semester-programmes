#include "bNode.h"


bNode::bNode(int data)
{
	this->data = data;
	leftchild = NULL;
	rightchild = NULL;
}
void bNode::set_data(int data)
{
	this->data = data;
}

bNode::~bNode()
{
}
