#pragma once
#include"Stak.h"
class Queue:public Stack
{
public:
	bool isEmpty();    //check list is empty or not
	void enqueue(node*);     //insert character in queue
	void dequeue();    //remove character from queue
	int getNoOfElement();   //return no of element in queue
};