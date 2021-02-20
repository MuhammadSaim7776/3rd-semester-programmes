#include "Queue.h"


Queue::Queue()
{
	front  = -1;
	rear = -1;
	noOfElements = 0;
}
void Queue::enqueue(int x)
{
	if (front == -1)
	{
		front = 0;
	}
	if (rear == MAX_SIZE - 1)
	{
		cout << "Queue is full. Element cannot be added\n";
	}
	else
	{
		rear = rear + 1;
		myqueue[rear] = x;
		noOfElements++;
		cout << "Element inserted successfully!!!\n";
	}
}
int Queue::dequeue()
{
	if (noOfElements==0)
	{
		cout << "Queue is empty. element cannot be removed\n";
	}
	else if (rear>front)
	{
		
		if (front == MAX_SIZE - 1 && noOfElements == 0)
		{
			cout << "Queue is empty. Element cant be removed\n";
		}
		else
		{
			int x = myqueue[front];
			front = front + 1;
			noOfElements--;
			return x;
			cout << "Element removed successfully!!!\n";
		}
	}
	else
	{
		if (front == MAX_SIZE - 1 && noOfElements == 0)
		{
			cout << "Queue is empty. Element cant be removed\n";
		}
		else
		{
			int x = myqueue[front];
			front = rear;
			noOfElements--;
			return x;
			cout << "Element removed successfully!!!\n";
		}
	}
}
bool Queue::isFull()
{
	if (noOfElements = MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Queue::isEmpty()
{
	if (noOfElements == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Queue::dislay()
{
	cout << "Front is at : " << front << endl;
	cout << "Rear is at : " << rear << endl;
	cout << "No Of Elements are : " << noOfElements << endl;
}
void Queue::showElements()
{
	int i = front;
	if (front == rear&&noOfElements!=0)
	{
		cout << myqueue[front] << endl;
	}
	else if (rear>front)
	{
		while (i != rear)
		{
			cout << myqueue[i] << "\t";
			i++;
		}
		cout << myqueue[i] << "\n";
	}
	else
	{
		cout << "queue is empty\n";
	}
	
}
Queue::~Queue()
{
}
