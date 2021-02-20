#pragma once
#include"Node.h"
class List
{
private:
	Node*header;
public:
	List();
	void insertionAtTail(Node*);
	void insertionAtHead(Node*);
	void insertionAtAnyPoint(Node*, Node*);
	void deletionAtHead();
	void deletionAtEnd();
	void deletionAtAnyPoint(Node*);
	int search(Node*);
	void display()const;
	void displayreverse()const;
	bool isEmpty();
	int sizeOfList();
	~List();
};

