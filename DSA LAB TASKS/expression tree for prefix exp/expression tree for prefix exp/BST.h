#pragma once
#include"BNode.h"
#include<string>
#include"Stack.h"
class BST
{
private:
	BNode*root;//pointing towards the first node of tree called as root
public:
	BST();//constructor
	void insertion(string);//function to insert node into tree
	bool isDigit(char);
	bool isOperator(char);
	BNode*remove(BNode*);
	BNode*minimum(BNode*);
	void inorder();//displaying tree nodes in in order form
	void preoeder();//displaying tree nodes in pre order form
	void postorder();//displaying tree nodes in post order form
	BNode* search(BNode*);//searching the node with particular data
	~BST();//destructor
};

