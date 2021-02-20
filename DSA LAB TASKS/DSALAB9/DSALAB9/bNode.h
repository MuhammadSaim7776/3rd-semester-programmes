#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class bNode
{
private:
	int data;
public:
	bNode*leftchild;
	bNode*rightchild;
	bNode(int);
	void set_data(int);
	~bNode();
};

