#include "AVLNode.h"


AVLNode::AVLNode()
{
	this->data = -1;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
	this->height = 0;
}
AVLNode::AVLNode(int data)
{
	this->data = data;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
	this->height = 0;
}
void AVLNode::set_data(int data)
{
	this->data = data;
}
void AVLNode::set_parent(AVLNode*parent)
{
	this->parent = parent;
}
void AVLNode::set_left(AVLNode*left)
{
	this->left = left;
}
void AVLNode::set_right(AVLNode*right)
{
	this->right = right;
}
void AVLNode::set_height(int height)
{
	this->height = height;
}
int AVLNode::get_data()
{
	return data;
}
int AVLNode::get_height()
{
	return height;
}
AVLNode* AVLNode::get_parent()
{
	return parent;
}
AVLNode* AVLNode::get_left()
{
	return left;
}
AVLNode* AVLNode::get_right()
{
	return right;
}
AVLNode::~AVLNode()
{
}
