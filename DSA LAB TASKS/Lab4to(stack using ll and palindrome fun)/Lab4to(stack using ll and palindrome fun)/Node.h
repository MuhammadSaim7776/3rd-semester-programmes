#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
private:
	char data;	
	Node* next;
public:
	Node(char);
	void setData(char x);
	char getData();
	void setNextPtr(Node*n);
	Node*getNextPtr()const;
	~Node();
};

