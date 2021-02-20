#include"Queue.h"
void main()
{
	Queue myQueue;
	myQueue.enqueue(20);
	myQueue.dislay();
	myQueue.showElements();
	cout << endl;
	myQueue.enqueue(30);
	myQueue.dislay();
	myQueue.showElements();
	cout << endl;
	myQueue.dequeue();
	myQueue.dislay();
	myQueue.showElements();
	cout << endl;
	myQueue.dequeue();
	myQueue.dislay();
	myQueue.showElements();
	cout << endl;
	myQueue.dequeue();
	myQueue.dislay();
	myQueue.showElements();
	cout << endl;
	_getch();
}