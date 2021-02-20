#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
#define MAX_SIZE 20
class Queue
{
private:
	int front;
	int rear;
	int noOfElements;
	int myqueue[MAX_SIZE];
public:
	Queue();
	bool isFull();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	void dislay();
	void showElements();
	~Queue();
};

