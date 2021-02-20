#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
private:
	char data;
	Node*nextNodePtr;
	Node*prevNodePtr;
public:
	Node(char);
	void setNextNodePtr(Node*);
	void setprevNodePtr(Node*);
	Node* getNextNodeptr()const;
	Node* getPrevNodePtr()const;
	char getData()const;
	void setData(char);
	~Node();
};

