#include "SNode.h"


SNode::SNode(AVLNode* x)
{
	data = x;
	next = NULL;
}
void SNode::setData(AVLNode* x)
{
	data = x;
}
AVLNode* SNode::getData()const
{
	return data;
}
void SNode::setNextPtr(SNode*n)
{
	next = n;
}
SNode*SNode::getNextPtr()const
{
	return next;
}
SNode::~SNode()
{
}
