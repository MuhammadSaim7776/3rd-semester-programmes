#include "BST.h"


BST::BST()
{
	root = NULL;//when the tree is created initially the root points to null showing that tree is empty
}
bool BST::isDigit(char n)
{
	if (n >= '0'&& n <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BST::isOperator(char n)
{
	if (n == '+' || n == '-' || n == '*' || n == '/' || n == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void BST::insertion(string str)
{
	Stack s1;
	Stack s2;
	int length = str.length()-1;
	for (int i = 0; i <= length; i++)
	{
		BNode* b = new BNode(str[length-i]);
		if (isDigit(b->get_data()) == true)
		{
			s1.push(new SNode(b));
		}
		else if (isOperator(b->get_data()) == true)
		{
			s2.push(new SNode(b));
			s2.top()->leftchild = s1.pop();
			s2.top()->rightchild = s1.pop();
			s1.push(new SNode(s2.pop()));
		}
		else
		{
			cout << "invalid content\n";
		}
	}
	root = s1.pop();
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
