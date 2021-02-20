#pragma once
#include"AVLNode.h"
#include"Stack.h"
#include"Queue.h"
//#include<algorithm>
class AVLTree
{
private:
	AVLNode*root;
public:
	AVLTree();
	AVLNode* singleRightRotation(AVLNode*);
	AVLNode* singleLeftRotation(AVLNode*);
	AVLNode* doubleRightLeftRotation(AVLNode*);
	AVLNode* doubleLeftRightRotation(AVLNode*);
	void AVLinsert(AVLNode*);
	void inorder();
	void levelorder();
	int max(int, int);
	int Height(AVLNode*);
	AVLNode*search(AVLNode*);
	AVLNode*minimum(AVLNode*);
	AVLNode*remove(AVLNode*);
	int get_balance(AVLNode*);
	AVLNode*get_root();
	~AVLTree();
};

