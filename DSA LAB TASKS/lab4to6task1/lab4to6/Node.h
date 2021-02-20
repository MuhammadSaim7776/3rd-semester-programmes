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
	void setData(char);
	char getData()const;
	void setNextPtr(Node*);
	Node*getNextPtr()const;
	~Node();
};