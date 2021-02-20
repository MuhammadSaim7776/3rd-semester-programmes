#pragma once
//This is the node class for stack and queue operations. This is needed because the node class of
// tree has hierarical structure. So it would be diffivcult to use tree node class in stack or queue
#include"AVLNode.h"
class SNode {
private:
	AVLNode*data;		// data
	SNode* next;		// pointer to next
public:
	SNode(AVLNode*);//parameterized constructor
	void setData(AVLNode*);//function to set data of node
	AVLNode* getData()const;//function to get data of node
	void setNextPtr(SNode*);//function to set next pointer of node
	SNode*getNextPtr()const;//function to get next pointer of node
	~SNode();//destructor

};
