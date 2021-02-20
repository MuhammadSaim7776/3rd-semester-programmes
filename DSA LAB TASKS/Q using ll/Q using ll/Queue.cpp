#include "Queue.h"


Queue::Queue()
{
	front = NULL;
	rear = NULL;
}
bool Queue::isEmpty()
{
	if (front == NULL&&rear == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Queue::enqueue(Node*n)
{
	if (isEmpty()==true)
	{
		front = n;
		rear = n;
	}
	else
	{
		rear->setNextPtr(n);
		rear = n;
	}
}
Node* Queue::dequeue()
{
	if (isEmpty() == true)
	{
		cout << "Operation cant be performes because queue is empty!!\n";
	}
	else if (front == rear)
	{
		Node*temp = front;
		temp->setNextPtr(NULL);
		front = NULL;
		rear = NULL;
		return temp;
		delete temp;

	}
	else
	{
		Node*temp = front;
		temp->setNextPtr(NULL);
		front = front->getNextPtr();
		return temp;
		delete temp;
	}
}

Queue::~Queue()
{
}
