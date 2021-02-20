#include "BST.h"


BST::BST()
{
	root = NULL;//when the tree is created initially the root points to null showing that tree is empty
}
void BST::insertion(BNode*n)
{
	BNode *temp = root;//runner pointer that locate the position of new node to be inserted
	BNode *btemp = NULL;
	if (temp == NULL)
	{
		root = n;//if tree is empty the root will begain pointing to first node
	}
	else
	{
		while (temp)//loop will remian execuiting untill temp will become equal to NULL
		{
			
			if (temp->get_data() > n->get_data())//locate the position where the new node will be indserted 
			{
				btemp = temp;
				temp = temp->leftchild;
			}
			else
			{
				btemp = temp;
				temp = temp->rightchild;
			}

		}
		if (btemp->get_data() > n->get_data())
		{
			btemp->leftchild = n;
			n->parent = btemp;
		}
		else
		{
			btemp->rightchild = n;
			n->parent = btemp;
		}
	}
}
void BST::inorder()
{
	BNode*rptr = root;
	Stack stak;
	if (rptr == NULL)
	{
		cout << "Tree ie empty!!\n";
	}
	else
	{
		cout << "Elements of tree according to inorder traversal are\n";
		while (stak.isEmpty() !=true || rptr !=NULL)//while loop checking empty stack or null rptr
		{
			if (rptr!= NULL)
			{
				stak.push(new SNode(rptr));//push the node pointed by runner pointer to stack if node exists
				rptr = rptr->leftchild;//move the runner pointer to left side of node
			}//push nodes untill left most found
			else
			{
				BNode *temp = stak.pop();//while moving toward left if the left most node is fount than remove it from stack
				cout << temp->get_data()<<"\t";//and also print that removed node
				rptr = temp->rightchild;//because left most node is visited, now move toward right

			}

		}
	}
}
void BST::preoeder()
{
	BNode*rptr = root;
	Stack stak;
	if (rptr == NULL)
	{
		cout << "Tree is empty\n";
	}
	else
	{
		cout << "\nElements of tree according to preorder traversal are\n";
		stak.push(new SNode(rptr));//push root node to stack
		while (stak.isEmpty() != true)//untill stack become empty
		{
			BNode*temp = stak.pop();//remove the pushed node from stack 
			cout << temp->get_data() << "\t";//print that node
			if (temp->rightchild != NULL)
			{
				stak.push(new SNode(temp->rightchild));//push right child of removed node first if exists because  
			}                                         //left child should be visited first 
			if (temp->leftchild != NULL)
			{
				stak.push(new SNode(temp->leftchild));//push left child of removed node if exists
			}
		}//loop will remian execuiting untill stack become empty. when one is removed from stack its right and left 
	}    //child will be pushedto stack turn by turn

}
void BST::postorder()
{
	//using two stacks
	BNode*rptr = root;
	BNode*temp = NULL;
	Stack s1,s2;
	if (rptr == NULL)
	{
		cout << "Tree is empty\n";
	}
	else
	{
		cout << "\nElements of tree according to postorder traversel are\n";
		s1.push(new SNode(rptr));//push root node to stack 1
		while (s1.isEmpty() != true)//loop will remain execuiting untill stack 1 become  empty
		{
			temp = s1.pop();//remove the top node
			s2.push(new SNode(temp));//push it into the stack2
			if (temp->leftchild != NULL)
			{
				s1.push(new SNode(temp->leftchild));//if the poped node has leftchild push it
				
			}
			if (temp->rightchild != NULL)
			{
				s1.push(new SNode(temp->rightchild)); //if the poped node has rightchild push it
			}
		}
		s2.display();//At end stack2 have elements in post order, so simply display it
	}
}


		//the commented code given right below is of  post order using 1 stack
		/*while (stak.isEmpty() != true || rptr != NULL)
		{
			if (rptr != NULL)
			{
				stak.push(new SNode(rptr));
				rptr = rptr->leftchild;
			}
			else
			{
				BNode*temp = NULL;
				temp = stak.top()->rightchild;
				if (temp == NULL)
				{
					temp=stak.pop();
					cout << temp->get_data() << "\t";
					while (stak.isEmpty() != true && temp == stak.top()->rightchild)
					{
						temp = stak.pop();
						cout << temp->get_data() << "\t";
					}
				}
				else
				{
					rptr = temp;
				}
			}
		}*/
//level by level traversal of tree using Queue
void BST :: levelorder()
{
	Queue Q;
	BNode*rptr = root;
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
			BNode*temp = Q.getfront();
			cout << temp->get_data() << "\t";//print the node at front of queue
			if (temp->leftchild != NULL)
			{
				Q.enqueue(new SNode(temp->leftchild));//enqueue the left child of front node if exists
			}
			if (temp->rightchild != NULL)
			{
				Q.enqueue(new SNode(temp->rightchild));//enqueue the right child of front node if exists

			}
			Q.dequeue();//remove the front node that is completely visited. Now we have its right and left child in
						//queue, so we can visite them later
		}//loop will break when queue become empty
	}
}
BNode* BST::search(BNode*n)
{
	BNode*rptr = root;
	while (rptr->get_data() != n->get_data())
	{
		if (rptr->get_data() > n->get_data())
		{
			rptr = rptr->leftchild;
		}
		else
		{
			rptr = rptr->rightchild;
		}
	}
	return rptr;
}
//Height is the no of nodes between root and leaf node having longest path from root node
//It is like level order traversal, So we use queue
int BST::height()
{
	BNode*rptr = root;
	int height = 0;
	int size = 0;
	Queue Q;
	if (rptr == NULL)
	{
		return 0;
	}
	else
	{
		Q.enqueue(new SNode(rptr));//enqueue root node
		while (Q.isEmpty() != true)
		{
			size = Q.size();//this variable keeps the no of nodes at current level
			while (size > 0)//this while loop will remain executing untill rptr move to next level after visiting all nodes
			{               //of current level
				BNode*temp = Q.getfront();
				if (temp->leftchild != NULL)
				{
					Q.enqueue(new SNode(temp->leftchild));//enqueue left child if exists
				}
				if (temp->rightchild != NULL)
				{
					Q.enqueue(new SNode(temp->rightchild));//enqueue right child if exists
				}
				Q.dequeue();//remove the node after visiting
				size--;//decrement size beacause a node at current level is visited 
			}
			height++;//when the next level reached increment height
		}
	}
	return height;
}
BNode* BST::minimum(BNode*n)
{
	BNode*temp = n;
	while (temp->leftchild != NULL)
	{
		temp = temp->leftchild;
	}
	return temp;
}
BNode* BST::remove(BNode*n)
{
	BNode*temp = NULL;
	temp=search(n);
	if (temp->leftchild == NULL && temp->rightchild == NULL)
	{
		if (temp == temp->parent->leftchild)
		{
			temp->parent->leftchild = NULL;
		}
		else
		{
			temp->parent->rightchild = NULL;
		}
	}
	else if (temp->leftchild != NULL &&temp->rightchild == NULL)
	{
		if (temp == temp->parent->leftchild)
		{
			temp->parent->leftchild = temp->leftchild;
		}
		else
		{
			temp->parent->rightchild = temp->leftchild;
		}
	}
	else if (temp->leftchild == NULL &&temp->rightchild != NULL)
	{
		if (temp == temp->parent->leftchild)
		{
			temp->parent->leftchild = temp->rightchild;
		}
		else
		{
			temp->parent->rightchild = temp->rightchild;
		}
	}
	else
	{
		BNode*min = NULL;
		min = minimum(temp->rightchild);
		temp->set_data(min->get_data());
		if (min == min->parent->leftchild)
		{
			min->parent->leftchild = min->rightchild;
		}
		else
		{
			min->parent->rightchild = min->rightchild;
		}
		delete min;
	}
	return temp;
	delete temp;

}
BST::~BST()
{
}
