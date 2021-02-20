#include<iostream>
#include<conio.h>
using namespace std;
class AVLNode
{
public:
	int key;
	AVLNode *left;
	AVLNode *right;
	int height;
	AVLNode(int);
};
AVLNode::AVLNode(int key)
{
	this->key = key;
	this->left = NULL;
	this->right = NULL;
	this->height = 1;   
}

class AVLTree
{
private:
	AVLNode*root;
public:
	AVLTree()
	{
		root = NULL;
	}
	int height(AVLNode *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	AVLNode *rightRotate(AVLNode *y)
	{
		AVLNode *x = y->left;
		AVLNode *T2 = x->right;  
		x->right = y;
		y->left = T2;
		y->height = max(height(y->left),
			height(y->right)) + 1;
		x->height = max(height(x->left),
			height(x->right)) + 1; 
		return x;
	}
	AVLNode *leftRotate(AVLNode *x)
	{
		AVLNode *y = x->right;
		AVLNode *T2 = y->left;
		y->left = x;
		x->right = T2; 
		x->height = max(height(x->left),
			height(x->right)) + 1;
		y->height = max(height(y->left),
			height(y->right)) + 1;  
		return y;
	}
	int getBalance(AVLNode *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) -
			height(N->right);
	}
	AVLNode* insert(AVLNode* node, int key)
	{
		if (node == NULL)
			return(new AVLNode(key));

		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		else  
			return node;
		node->height = 1 + max(height(node->left),
			height(node->right));
		int balance = getBalance(node);
		if (balance > 1 && key < node->left->key)
			return rightRotate(node); 
		if (balance < -1 && key > node->right->key)
			return leftRotate(node);  
		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		} 
		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
	AVLNode * minValueNode(AVLNode* node)
	{
		AVLNode* current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	}
	AVLNode* deleteNode(AVLNode* root, int key)
	{
  
		if (root == NULL)
			return root; 
		if (key < root->key)
			root->left = deleteNode(root->left, key); 
		else if (key > root->key)
			root->right = deleteNode(root->right, key);  
		else
		{ 
			if ((root->left == NULL) ||(root->right == NULL))
			{
				AVLNode *temp = root->left ?
					root->left :
					root->right; 
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else  
					*root = *temp;   
				free(temp);
			}
			else
			{  
				AVLNode* temp = minValueNode(root->right); 
				root->key = temp->key;
				root->right = deleteNode(root->right,
					temp->key);
			}
		}
		if (root == NULL)
			return root;
		root->height = 1 + max(height(root->left),
			height(root->right)); 
		int balance = getBalance(root);  
		if (balance > 1 &&
			getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance > 1 &&
			getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		} 
		if (balance < -1 &&
			getBalance(root->right) <= 0)
			return leftRotate(root);  
		if (balance < -1 &&
			getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}
	void preOrder(AVLNode *root)
	{
		if (root != NULL)
		{
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	void INSERT(int key)
	{
		root=insert(root, key);
	}
	void PREORDER()
	{
		preOrder(root);
	}
	void remove(int k)
	{
		root=deleteNode(root, k);
	}
};
void main()
{
	AVLTree tree;
	tree.INSERT(9);
	tree.INSERT(5);
	tree.INSERT(10);
	tree.INSERT(0);
	tree.INSERT(6);
	tree.INSERT(11);
	tree.INSERT(-1);
	tree.INSERT(1);
	tree.INSERT(2);
	tree.PREORDER();
	tree.remove(10);
	cout << "\nAfter deleting 10\n";
	tree.PREORDER();

	_getch();
}

