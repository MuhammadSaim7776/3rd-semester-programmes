#include "AVLTree.h"


AVLTree::AVLTree()
{
	root = NULL;
}
AVLNode* AVLTree::singleRightRotation(AVLNode* k2)
{
	bool status = false;
	AVLNode*k1 = NULL;
	int h = 0;
	AVLNode*p = k2->get_parent();
	if (p != NULL&&k2 == p->get_right())
	{
		status = true;
	}
	else
	{
		status = false;
	}
	if (k2 == NULL)
	{
		return NULL;
	}
	else
	{
		k1 = k2->get_left();
		k2->set_left(k1->get_right());
		k1->set_right(k2);
		k2->set_parent(k1);
		k1->set_parent(p);
		if (p != NULL)
		{
			if (status == true)
			{
				p->set_right(k1);
			}
			else
			{
				p->set_left(k1);
			}
		}
		else
		{
			root = k1;
		}
		h = max(Height(k2->get_left()), Height(k2->get_right()));
		k2->set_height(h + 1);
		h = max(Height(k1->get_left()), Height(k1->get_right()));
		k1->set_height(h + 1);
		return k1;
	}	
}
AVLNode* AVLTree::singleLeftRotation(AVLNode* k1)
{
	bool status = false;
	AVLNode*p = k1->get_parent();
	if (p != NULL&&k1 == p->get_left())
	{
		status = true;
	}
	else
	{
		status = false;
	}
	AVLNode*k2 = NULL;
	int h = 0;
	if (k1 == NULL)
	{
		return NULL;
	}
	else
	{
		k2 = k1->get_right();
		k1->set_parent(NULL);
		k1->set_right(k2->get_left());
		k2->set_left(k1);
		k1->set_parent(k2);
		k2->set_parent(p);
		if (p != NULL)
		{
			if (status == true)
			{
				p->set_left(k2);
			}
			else
			{
				p->set_right(k2);
			}	
		}
		else
		{
			root = k2;
		}
		h = max(Height(k1->get_left()), Height(k1->get_right()));
		k1->set_height(h + 1);
		h = max(Height(k2->get_left()), Height(k2->get_right()));
		k2->set_height(h + 1);
		return k2;
	}
}
AVLNode* AVLTree::doubleRightLeftRotation(AVLNode*k1)
{
	if (k1 == NULL)
	{
		return NULL;
	}
	else
	{
		singleRightRotation(k1->get_right());
		return singleLeftRotation(k1);
	}
}
AVLNode* AVLTree::doubleLeftRightRotation(AVLNode*k3)
{
	if (k3 == NULL)
	{
		return NULL;
	}
	else
	{
		singleLeftRotation(k3->get_left());
		return singleRightRotation(k3);
	}
}
void AVLTree::AVLinsert(AVLNode* node)
{
	AVLNode*temp = root;
	AVLNode*prev = NULL;
	int heit = 0;
	int diff = 0;
	while (temp != NULL)
	{
		if (node->get_data() < temp->get_data())
		{
			prev = temp;
			temp = temp->get_left();
		}
		else
		{
			prev = temp;
			temp = temp->get_right();
		}

	}
	if (root == NULL)
	{
		root = node;
	}
	else if (node->get_data() < prev->get_data())
	{
		node->set_parent(prev);
		prev->set_left(node);
	}
	else
	{
		node->set_parent(prev);
		prev->set_right(node);
	}
	if (prev != NULL)
	{
		heit = max(Height(prev->get_left()), Height(prev->get_right()));
		prev->set_height(heit + 1);

		if (prev->get_parent() != NULL)
		{
			prev = prev->get_parent();
			heit = max(Height(prev->get_left()), Height(prev->get_right()));
			/*heit = max(Height(prev->get_left()), Height(prev->get_right()));*/
			prev->set_height(heit + 1);
		}
		diff = get_balance(prev);
		if (diff > 1 && node->get_data()<prev->get_left()->get_data())
		{
			prev = singleRightRotation(prev);
		}
		else if (diff > 1 && node->get_data() > prev->get_left()->get_data())
		{
			prev = doubleLeftRightRotation(prev);
		}
		else if (diff<-1 && node->get_data()>prev->get_right()->get_data())
		{
			prev = singleLeftRotation(prev);
		}
		else if (diff < -1 && node->get_data() < prev->get_right()->get_data())
		{
			prev = doubleRightLeftRotation(prev);
		}
	}
	/*cout << root->get_data();*/
	prev = node;
	while (prev != NULL)
	{
		heit = max(Height(prev->get_left()), Height(prev->get_right()));
		prev->set_height(heit + 1);
		prev = prev->get_parent();
	}
}
	

void AVLTree::inorder()
{
	AVLNode*rptr = root;
	Stack stak;
	if (rptr == NULL)
	{
		cout << "Tree ie empty!!\n";
	}
	else
	{
		cout << "Elements of tree according to inorder traversal are\n";
		while (stak.isEmpty() != true || rptr != NULL)//while loop checking empty stack or null rptr
		{
			if (rptr != NULL)
			{
				stak.push(new SNode(rptr));//push the node pointed by runner pointer to stack if node exists
				rptr = rptr->get_left();//move the runner pointer to left side of node
			}//push nodes untill left most found
			else
			{
				AVLNode *temp = stak.pop();//while moving toward left if the left most node is fount than remove it from stack
				cout << temp->get_data() << "\t";//and also print that removed node
				rptr = temp->get_right();//because left most node is visited, now move toward right

			}

		}
	}
}
void AVLTree::levelorder()
{
	Queue Q;
	AVLNode*rptr = root;
	if (rptr == NULL)
	{
		cout << "Tree is Empty";
	}
	else
	{
		cout << "The elements of tree according to level order traversal are\n";
		Q.enqueue(new SNode(rptr));//enqueue the root node
		while (Q.isEmpty() != true)
		{
			AVLNode*temp = Q.getfront();
			cout << temp->get_data() <<","<< get_balance(temp)<<"\t";//print the node at front of queue
			if (temp->get_left() != NULL)
			{
				Q.enqueue(new SNode(temp->get_left()));//enqueue the left child of front node if exists
			}
			if (temp->get_right() != NULL)
			{
				Q.enqueue(new SNode(temp->get_right()));//enqueue the right child of front node if exists

			}
			Q.dequeue();//remove the front node that is completely visited. Now we have its right and left child in
			//queue, so we can visite them later
		}//loop will break when queue become empty
	}

}
AVLNode* AVLTree::search(AVLNode*n)
{
	AVLNode*rptr = root;
	while (rptr->get_data() != n->get_data())
	{
		if (rptr->get_data() > n->get_data())
		{
			rptr = rptr->get_left();
		}
		else
		{
			rptr = rptr->get_right();
		}
	}
	return rptr;
}
AVLNode* AVLTree::minimum(AVLNode*n)
{
	AVLNode*temp = n;
	while (temp->get_left() != NULL)
	{
		temp = temp->get_left();
	}
	return temp;
}
AVLNode* AVLTree::remove(AVLNode*n)
{
	AVLNode*temp = NULL;
	AVLNode*prnt = NULL;
	int heit = 0;
	int diff = 0;
	temp = search(n);
	prnt = temp->get_parent();
	if (temp->get_left() == NULL && temp->get_right() == NULL)
	{
		if (temp == temp->get_parent()->get_left())
		{
			temp->get_parent()->set_left(NULL);
		}
		else
		{
			temp->get_parent()->set_right(NULL);
		}
	}
	else if (temp->get_left() != NULL &&temp->get_right() == NULL)
	{
		if (temp == temp->get_parent()->get_left())
		{
			temp->get_parent()->set_left(temp->get_left());
		}
		else
		{
			temp->get_parent()->set_right(temp->get_left());
		}
	}
	else if (temp->get_left() == NULL &&temp->get_right() != NULL)
	{
		if (temp == temp->get_parent()->get_left())
		{
			temp->get_parent()->set_left(temp->get_right());
		}
		else
		{
			temp->get_parent()->set_right(temp->get_right());
		}
	}
	else
	{
		AVLNode*min = NULL;
		min = minimum(temp->get_right());
		temp->set_data(min->get_data());
		if (min == min->get_parent()->get_left())
		{
			min->get_parent()->set_left(min->get_right());
		}
		else
		{
			min->get_parent()->set_right(min->get_right());
		}
		delete min;
	}
	return temp;
	delete temp;
	/*heit = max(Height(prnt->get_left()), Height(prnt->get_right()));
	prnt->set_height(heit + 1);
	diff = get_balance(prnt);*/

}
int AVLTree::Height(AVLNode*n)
{
	if (n == NULL)
	{
		return -1;
	}
	else
	{
		return n->get_height();
	}
}
int AVLTree::get_balance(AVLNode*n)
{
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		return(Height(n->get_left()) - Height(n->get_right()));
	}
}
AVLTree::~AVLTree()
{
	delete root;
}
int AVLTree::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
AVLNode*AVLTree::get_root()
{
	return root;
}
	
	//	AVLNode*temp = root;
	//	AVLNode*prev = NULL;
	//	int h = 0;
	//	int hdiff = 0;
	//	while (temp != NULL)
	//	{
	//		if (node->get_data() < temp->get_data())
	//		{
	//			prev = temp;
	//			temp = temp->get_left();
	//		}
	//		else
	//		{
	//			prev = temp;
	//			temp = temp->get_right();
	//		}
	//	}
	//	if (root == NULL)
	//	{
	//		root = node;
	//	}
	//	else if (node->get_data() < prev->get_data())
	//	{
	//		node->set_parent(prev);
	//		prev->set_left(node);
	//		h = max(height(prev->get_right()), height(prev->get_left()));
	//		prev->set_height(h + 1);
	//		hdiff = height(prev->get_left()) - height(prev->get_right());
	//		if (hdiff == 2)
	//		{
	//			if (node->get_data() < prev->get_left()->get_data())
	//			{
	//				prev = singleRightRotation(prev);
	//			}
	//			else
	//			{
	//				prev = doubleRightLeftRotation(prev);
	//			}
	//		}
	//	}
	//	else
	//	{
	//		node->set_parent(prev);
	//		prev->set_right(node);
	//		int rig = height(prev->get_right());
	//		int lef = height(prev->get_left());
	//		h = max(height(prev->get_right()), height(prev->get_left()));
	//		prev->set_height(h + 1);
	//		hdiff = height(prev->get_right()) - height(prev->get_left());
	//		if (hdiff == 2)
	//		{
	//			if (node->get_data() > prev->get_right()->get_data())
	//			{
	//				prev = singleLeftRotation(prev);
	//			}
	//			else
	//			{
	//				prev = doubleRightLeftRotation(prev);
	//			}
	//		}
	//	}
	//	cout << root->get_data();
	//}

//while (prev != NULL)
//{
//	if (prev != NULL)
//	{
//		heit = max(Height(prev->get_left()), Height(prev->get_right()));
//		prev->set_height(heit + 1);
//
//		if (prev->get_parent() != NULL)
//		{
//			prev = prev->get_parent();
//			heit = max(Height(prev->get_left()), Height(prev->get_right()));
//			/*heit = max(Height(prev->get_left()), Height(prev->get_right()));*/
//			prev->set_height(heit + 1);
//		}
//		diff = get_balance(prev);
//		if (diff > 1 && node->get_data()<prev->get_left()->get_data())
//		{
//			prev = singleRightRotation(prev);
//		}
//		else if (diff > 1 && node->get_data() > prev->get_left()->get_data())
//		{
//			prev = doubleLeftRightRotation(prev);
//		}
//		else if (diff<-1 && node->get_data()>prev->get_right()->get_data())
//		{
//			prev = singleLeftRotation(prev);
//		}
//		else if (diff < -1 && node->get_data() < prev->get_right()->get_data())
//		{
//			prev = doubleRightLeftRotation(prev);
//		}
//	}
//	prev = prev->get_parent();
//}