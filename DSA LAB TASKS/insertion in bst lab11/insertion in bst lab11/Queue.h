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
	BNode* dequeue();
	bool isEmpty();
	int size();
	BNode* getfront();
};

