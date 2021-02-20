#pragma once
#include"SNode.h"
class Stack {
private:
	SNode*head;
public:
	Stack() // constructor
	{
		head = NULL;
	}
	~Stack()
	{
	}// destructor
	void push(SNode*);
	AVLNode* pop();
	AVLNode* top();
	bool isEmpty();
	void display()const;
};
