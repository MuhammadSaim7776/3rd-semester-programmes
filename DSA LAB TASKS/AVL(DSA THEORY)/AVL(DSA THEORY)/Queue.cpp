#include "Queue.h"


Queue::Queue()
{
	front = NULL;
	rear = NULL;

}
void Queue::enqueue(SNode*n)
{
	if (rear != NULL)
	{
		rear->setNextPtr(n);
		rear =n;
	}
	else
	{
		rear = n;
		front = n;
	}


}
AVLNode* Queue::dequeue()
{
	AVLNode*temp = front->getData();
	SNode *p = front;
	front = front->getNextPtr();
	delete p;
	return temp;

}
bool Queue::isEmpty()
{

	return (front == NULL);
}
AVLNode* Queue::getfront()
{

	return front->getData();
}
int Queue::size()
{
	int size = 0;
	SNode*rptr = front;
	while (rptr != NULL)
	{
		size++;
		rptr = rptr->getNextPtr();
	}
	return size;
}