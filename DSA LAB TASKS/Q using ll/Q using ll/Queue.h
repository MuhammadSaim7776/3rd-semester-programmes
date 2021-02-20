#pragma once
#include"Node.h"
class Queue
{
private:
	
public:
	Node*front;
	Node*rear;
	Queue();
	void enqueue(Node*);
	Node*dequeue();
	bool isEmpty();
	~Queue();
};

