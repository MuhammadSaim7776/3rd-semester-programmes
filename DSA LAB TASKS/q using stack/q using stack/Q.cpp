#include<iostream>
#include"Nod.h"
#include "Q.h"
using namespace std;
bool Queue::isEmpty()    //check array is empty or not
{
	return isStackEmpty();
}
void Queue::enqueue(node* n)     //insert character in queue
{
	Push(n);
	cout << "The node with data " << n->getData() << " is entered successfully to queue\n";
}
void Queue::dequeue()    //remove character from queue
{
	if (!isEmpty())
	{
		Stack s;
		int till=sizeOfStack();
		for (int i = 0; i <till ; i++)
		{
			s.Push(new node(Pop()));
		}
		int x=s.Pop();
		cout << "The data entered first i.e. " << x << " is deleted successfully from queue\n";
		for (int i = 0; i < till-1; i++)
		{
			Push(new node(s.Pop()));
		}
	}
	else
	{
		cout << "Queue is Empty. Action cant be performed" << endl;
	}
}
int Queue::getNoOfElement()    //return no of element in queue
{
	return sizeOfStack();
}
