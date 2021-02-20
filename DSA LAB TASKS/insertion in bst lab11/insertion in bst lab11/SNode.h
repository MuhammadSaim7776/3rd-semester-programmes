#pragma once
//This is the node class for stack and queue operations. This is needed because the node class of
// tree has hierarical structure. So it would be diffivcult to use tree node class in stack or queue
#include"BNode.h"
class SNode {
private:
	BNode*data;		// data
	SNode* next;		// pointer to next
public:
	SNode(BNode*);//parameterized constructor
	void setData(BNode*);//function to set data of node
	BNode* getData()const;//function to get data of node
	void setNextPtr(SNode*);//function to set next pointer of node
	SNode*getNextPtr()const;//function to get next pointer of node
	~SNode();//destructor

};
