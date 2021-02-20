#pragma once
#include"Node.h"
static int arr[10] = {0};
class Hash
{
private:
	int capacity;
	Node**Table;
	void reset_indices();
	int hash();
	void decTOBin(int);
public:
	Hash(int);
	void insert(Node*);
	int search(Node*);
	void remove(Node*);
	void  display();
	~Hash();
};

