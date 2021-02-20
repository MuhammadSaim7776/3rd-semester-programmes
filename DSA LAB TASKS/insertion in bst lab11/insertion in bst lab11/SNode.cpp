#include "SNode.h"


SNode::SNode(BNode* x)
{
	data = x;
	next = NULL;
}
void SNode::setData(BNode* x)
{
	data = x;
}
BNode* SNode::getData()const
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
