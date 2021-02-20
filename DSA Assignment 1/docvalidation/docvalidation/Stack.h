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
	string top();
	bool isEmpty();
	void display();
	~Stack();
};

