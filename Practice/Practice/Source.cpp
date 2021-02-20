#include<iostream>
#include<conio.h>
using namespace std;
//node class
class BNode
{
	char data;
public:
	BNode* leftchild;
	BNode* rightchild;
	BNode* parent;
	BNode(char);
	void set_data(char);
	char get_data()const;
	
};
BNode::BNode(char data)
{
	this->data = data;
	leftchild = NULL;
	rightchild = NULL;
	parent = NULL;
}
void BNode::set_data(char data)
{
	this->data = data;
}
char BNode::get_data()const
{
	return data;
}
// binary search tree class
class BST
{
private:
	BNode* root;
public:
	BST();
	void Insertion(BNode*);
	BNode* search(BNode*);
	void Inorder(BNode*);
	void preorder(BNode* node);
	void postorder(BNode* node);
	BNode* Delete(BNode*);
	BNode* minimum(BNode*);
	void displayp();
	void displaypost();
	void displayi();



};
BST::BST()
{
	root = NULL;
}
// Delete function
BNode* BST::Delete(BNode* n)
{
	BNode* ptr = NULL;
	ptr = search(n);
	if (ptr->leftchild == NULL && ptr->rightchild == NULL)
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = NULL;
		}
		else
		{
			ptr->parent->rightchild = NULL;
		}
	}
	else if (ptr->leftchild != NULL && ptr->rightchild == NULL)
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = ptr->leftchild;
		}
		else
		{
			ptr->parent->rightchild = ptr->leftchild;
		}
	}
	else if (ptr->leftchild == NULL && ptr->rightchild != NULL)
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = ptr->rightchild;
		}
		else
		{
			ptr->parent->rightchild = ptr->rightchild;
		}
	}
	else
	{
		BNode* min = NULL;
		min = minimum(ptr->rightchild);
		ptr->set_data(min->get_data());
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
	return ptr;
	delete ptr;

}
//minimum function
BNode* BST::minimum(BNode* n)
{
	BNode* temp = n;
	while (temp->leftchild != NULL)
	{
		temp = temp->leftchild;
	}
	return temp;
}
//insert function
void BST::Insertion(BNode* n)
{
	BNode* ptr = root;
	BNode* rptr = NULL;
	if (ptr == NULL)
	{
		root = n;
	}
	else
	{
		while (ptr)
		{

			if (ptr->get_data() > n->get_data())
			{
				rptr = ptr;
				ptr = ptr->leftchild;
			}
			else
			{
				rptr = ptr;
				ptr = ptr->rightchild;
			}

		}
		if (rptr->get_data() > n->get_data())
		{
			rptr->leftchild = n;
			n->parent = rptr;
		}
		else
		{
			rptr->rightchild = n;
			n->parent = rptr;
		}
	}
}
//search function
BNode* BST::search(BNode* n)
{
	BNode* ptr = root;
	while (ptr->get_data() != n->get_data())
	{
		if (ptr->get_data() > n->get_data())   // if root > n node  then leftchild
		{
			ptr = ptr->leftchild;
		}
		else
		{
			ptr = ptr->rightchild;
		}
	}
	return ptr;
}

void BST::Inorder(BNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		Inorder(BSTNode->leftchild);
		cout << BSTNode->get_data() << " ";
		Inorder(BSTNode->rightchild);
	}
}
void BST::preorder(BNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		cout << BSTNode->get_data() << " ";
		preorder(BSTNode->leftchild);
		preorder(BSTNode->rightchild);
	}
}
void BST::postorder(BNode* BSTNode)
{
	if (BSTNode != NULL)
	{
		postorder(BSTNode->leftchild);
		postorder(BSTNode->rightchild);
		cout << BSTNode->get_data() << " ";
	}
}


void BST::displayp()
{
	preorder(root);
}
void BST::displayi()
{
	Inorder(root);
}
void BST::displaypost()
{
	postorder(root);
}
//main driver program
void main()
{
	BST b;
	cout << "----> Binary search tree program <---- \n";
	b.Insertion(new BNode('z'));
	b.Insertion(new BNode('c'));
	b.Insertion(new BNode('d'));
	b.Insertion(new BNode('f'));
	b.Insertion(new BNode('b'));
	cout << "Pre-order display \n";
	b.displayp();
	cout << "\n post-order display \n";
	b.displaypost();
	cout << "\nDelete a node \n" << b.Delete(new BNode('d'));
	cout << "\n In-order display \n";
	b.displayi();
	_getch();
}