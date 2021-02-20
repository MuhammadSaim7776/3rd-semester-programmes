//This is the node class for tree 
#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class BNode
{
	char data;//data of node
public:
	BNode*parent;
	BNode*leftchild;//pointing toward leftchild of current node
	BNode*rightchild;//pointing toward rightchild of current node
	BNode(char);//parmeterized constructor
	void set_data(char);//function to set data
	char get_data()const;//function to get data
	~BNode();//destructor
};

