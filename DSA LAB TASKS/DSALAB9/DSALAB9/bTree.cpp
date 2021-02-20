#include "bTree.h"
bool bTree::is_perfect(bNode*m)
{
	bNode*runner=m
}
int bTree::insert(bNode*n)
{
	bNode*temp = root;
	if (root == NULL)
	{
		root = n;
	}
	else
	{
		while (temp->rightchild != NULL&&temp->leftchild != NULL)
		{
			if (is_perfect(temp) == false)
			{
				if (temp->leftchild == NULL)
				{
					temp = temp->leftchild;
					lcount++;
				}
				else
				{
					temp = temp->rightchild;
					lcount++;
				}
			}
			else
			{
				temp = temp->leftchild;


			}
		}
	}
}

//bTree::~bTree()
//{
//
//}
