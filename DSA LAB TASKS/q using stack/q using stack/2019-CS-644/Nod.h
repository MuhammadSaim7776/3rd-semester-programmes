
#pragma once
class node //node class
{
	int data;     //private data member to hold integer data type
	node* nextnodeptr;     //pointer(next node addressing)
public:
	node();       //Default constructor to set integer data to zero
	node(int);       //parameterize constructor to set integer data
	node* getNextNodeptr()const;    //getter funtion retuen next node pointer
	void  setNextNodeptr(node*);    //setter function to set next node pointer 
	int getData()const;    //return node integer data
	void setData(int);   //set node integer data
	~node();  //destructor of the node class
};
