#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Node
{
private:
	string data;
	Node* next;
public:
	Node(string);
	void setData(string);
	string getData()const;
	void setNextPtr(Node*);
	Node*getNextPtr()const;
	~Node();
};

