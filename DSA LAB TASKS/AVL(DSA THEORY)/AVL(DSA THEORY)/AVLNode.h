#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
class AVLNode
{
private:
	int data;
	AVLNode*parent;
	AVLNode*left;
	AVLNode*right;
	int height;
public:
	
	AVLNode();
	AVLNode(int);
	void set_data(int);
	void set_parent(AVLNode*);
	void set_right(AVLNode*);
	void set_left(AVLNode*);
	void set_height(int);
	int get_data();
	int get_height();
	AVLNode* get_parent();
	AVLNode* get_left();
	AVLNode* get_right();
	~AVLNode();
};

