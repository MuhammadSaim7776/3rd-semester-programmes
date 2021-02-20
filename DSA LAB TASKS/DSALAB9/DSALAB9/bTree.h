#pragma once
#include"bNode.h"
class bTree
{
private:
	bNode*root;
public:
	int n;
	int lcount;
	int rcount;
	bTree()
	{
		root = NULL;
		lcount = 0;
		rcount = 0;
	}
	bool is_perfect(bNode*);
	int insert(bNode*);
	~bTree();
};

