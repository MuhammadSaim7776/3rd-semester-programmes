#pragma once
#include"SNode.h"
class Queue
{
private:
	SNode* front;
	SNode* rear;
public:
	Queue();
	void enqueue(SNode*);
	AVLNode* dequeue();
	bool isEmpty();
	int size();
	AVLNode* getfront();
};

