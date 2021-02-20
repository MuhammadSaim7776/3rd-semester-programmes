#include<iostream>
using namespace std;
#include "Stak.h"
#include"Nod.h"

Stack::Stack()     //Default constructor
{
	header = nullptr;
}
void Stack::Push(node* n)    //insertionAtHead(NODE) [insertion before the first node]
{
	if (!header)
	{
		header = n;
	}
	else
	{
		node* rptr = header;
		header = n;
		n->setNextNodeptr(rptr);
	}
}
int Stack::Pop()     //delete Top element of stack if present
{
	if (isStackEmpty())
	{
		cout << "List Is Already Empty" << endl;
		return 0;
	}
	else
	{
		node* rptr = header;
		header = rptr->getNextNodeptr();
		int data = rptr->getData();
		delete rptr;
		return data;
	}
}
void Stack::Top()    //Print the Top value of stack
{
	if (!isStackEmpty())
	{
		cout << "Value At Top Is " << header->getData() << endl;
	}
	else
	{
		cout << "Stack Is Empty" << endl;
	}
}
bool Stack::isStackEmpty()  //check Stack is empty or not
{
	if (header == nullptr)
	{
		return true;
	}
	return false;
}
int Stack::sizeOfStack()    //calculate and return the size of Stack
{
	int size = 0;
	node* rptr = header;
	while (rptr)
	{
		size++;
		rptr = rptr->getNextNodeptr();
	}
	return size;
}
Stack::~Stack()    //destructor that delete Stack
{
	node* current = header, * next = nullptr;
	while (current)
	{
		next = current->getNextNodeptr();
		delete current;
		current = next;
	}
}
