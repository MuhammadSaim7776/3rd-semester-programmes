#include "List.h"


List::List()
{
	header = NULL;
}
void List::insertionAtTail(Node*n)
{
	Node*rptr = header;
	if (rptr == NULL)
	{
		header = n;
	}
	else
	{
		while (rptr->getNextNodeptr()!=NULL)
		{
			rptr = rptr->getNextNodeptr();
		}
		n->setprevNodePtr(rptr);
		rptr->setNextNodePtr(n);
	}
}
void List::insertionAtHead(Node*n)
{
	Node*rptr = header;
	rptr->setprevNodePtr(n);
	n->setNextNodePtr(rptr);
	header = n;
}
void List::insertionAtAnyPoint(Node*newNode,Node*n)
{
	Node*rptr = header;
	while (rptr->getData() != n->getData())
	{
		rptr = rptr->getNextNodeptr();
	}
	newNode->setNextNodePtr(rptr->getNextNodeptr());
	newNode->getNextNodeptr()->setprevNodePtr(newNode);
	rptr->setNextNodePtr(newNode);
	newNode->setprevNodePtr(rptr);
}
void List::deletionAtHead()
{
	Node*rptr = header;
	header = rptr->getNextNodeptr();
	header->setprevNodePtr(NULL);
	delete rptr;
}
void List::deletionAtEnd()
{
	Node*rptr = header;
	while (rptr->getNextNodeptr() != NULL)
	{
		rptr = rptr->getNextNodeptr();
	}
	rptr->getPrevNodePtr()->setNextNodePtr(NULL);
	delete rptr;
}
//void List::deletionAtAnyPoint(Node*n)
//{
//	Node*ptr = header;
//	while (ptr->getData() != n->getData())
//	{
//		ptr = ptr->getNextNodeptr();
//	}
//	if (ptr->getPrevNodePtr() == NULL)
//	{
//		header = ptr->getNextNodeptr();
//		ptr->getNextNodeptr()->setprevNodePtr(NULL);
//	}
//	else if (ptr->getNextNodeptr() == NULL)
//	{
//		ptr->getPrevNodePtr()->setNextNodePtr(NULL);
//	}
//	else
//	{
//		ptr->getPrevNodePtr()->setNextNodePtr(ptr->getNextNodeptr());
//		ptr->getNextNodeptr()->setprevNodePtr(ptr->getPrevNodePtr());
//	}
//	delete ptr;
//}
int List::search(Node* n)
{
	int count = 1;
	Node*rptr = header;
	while (rptr->getData() != n->getData())
	{
		rptr = rptr->getNextNodeptr();
		count++;
	}
	return count;
	delete rptr;	
}
void List::display()const
{
	Node*rptr = header;
	while (rptr->getNextNodeptr() != NULL)
	{
		cout << rptr->getData() << "\t";
		rptr = rptr->getNextNodeptr();
	}
	cout << rptr->getData() << endl;
}
void List::displayreverse()const
{
	Node*rptr = header;
	while (rptr->getNextNodeptr() != NULL)
	{
		rptr = rptr->getNextNodeptr();
	}
	while (rptr->getPrevNodePtr() != NULL)
	{
		cout << rptr->getData() << "\t";
		rptr = rptr->getPrevNodePtr();
	}
	cout << rptr->getData() << "\n";
}
bool List::isEmpty()
{
	if (header == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int List::sizeOfList()
{
	int size = 0;
	Node*rptr = header;
	while (rptr->getNextNodeptr() != NULL)
	{
		rptr = rptr->getNextNodeptr();
		size++;
	}
	size++;
	return size;
}
List::~List()
{
}
