#include<iostream>
#include<conio.h>
#include"Q.h"
#include"Nod.h"
using namespace std;

void main()
{
	Queue q;
	q.enqueue(new node(1));
	q.enqueue(new node(2));
	q.enqueue(new node(3));
	q.enqueue(new node(4));
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	_getch();
}