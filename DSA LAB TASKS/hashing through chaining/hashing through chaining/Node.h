#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
private:
	int Data;
	Node*Next;
public:
	Node();
	Node(int);
	void set_Data(int);
	void set_Next(Node*);
	int get_Data();
	Node* get_Next();
	~Node();
};

