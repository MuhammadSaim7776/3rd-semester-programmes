#pragma once
#include"Node.h"
class Stack
{
private:
	Node*head;
public:
	Stack();
	void push(Node*);
	void pop();
	char top();
	bool isEmpty();
	void display()const;
	~Stack();
};

