#pragma once
#include <iostream>
#include<string>
#include<conio.h>
using namespace std;
#define MAXSIZE 3 
class cStack
{
private:
	int top;
public:
	string stringStack[MAXSIZE];
	cStack();
	bool push(string x);
	string pop();
	string mtop();
	bool isEmpty();
	bool isFull();
	void displayReverse();
	~cStack();
};

