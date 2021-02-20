#include<iostream>
using namespace std;

#include "Nod.h"

node::node()       //Default constructor 
{
	data = 0;     //set integer data to zero
	nextnodeptr = nullptr;    //initialization pointer to NULL
}
node::node(int data)       //parameterize constructor
{
	this->data = data;    //set integer data
	nextnodeptr = nullptr;     //initialization pointer to NULL
}
node* node::getNextNodeptr()const    //getter funtion retuen next node pointer
{
	return nextnodeptr;
}
void  node::setNextNodeptr(node* nextnodeptr)    //setter function to set next node pointer 
{
	this->nextnodeptr = nextnodeptr;
}
int node::getData()const    //return node integer data
{
	return data;
}
void node::setData(int data)   //set node integer data
{
	this->data = data;
}
node::~node()   //destructor of node class
{
}
