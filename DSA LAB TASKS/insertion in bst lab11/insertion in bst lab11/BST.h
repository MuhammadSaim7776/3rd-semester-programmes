#pragma once
#include"BNode.h"
#include"Stack.h"
#include"Queue.h"
class BST
{
private:
	BNode*root;//pointing towards the first node of tree called as root
public:
	BST();//constructor
	void insertion(BNode*);//function to insert node into tree
	BNode*remove(BNode*);
	BNode*minimum(BNode*);
	void inorder();//displaying tree nodes in in order form
	void preoeder();//displaying tree nodes in pre order form
	void postorder();//displaying tree nodes in post order form
	void levelorder();//displaying tree nodes in level order form
	BNode* search(BNode*);//searching the node with particular data
	int height();//height of tree
	~BST();//destructor
};

