#include"Queue.h"
void main()
{
	Queue q;
	q.enqueue(new Node('a'));
	q.enqueue(new Node('b'));
	q.enqueue(new Node('c'));
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	_getch();

}