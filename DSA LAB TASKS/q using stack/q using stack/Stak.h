#pragma once
#include"Nod.h"
class Stack
{
	node* header;
public:
	Stack();     //Default constructor
	void Push(node*);     //insertionAtHead(NODE) [insertion before the first node]
	int Pop();       //delete Top element of stack if present
	bool isStackEmpty();    //check Stack is empty or not
	void Top(); //Print the Top value of stack
	int sizeOfStack();    //calculate and return the size of Stack
	~Stack();    //destructor that delete Stack
};
