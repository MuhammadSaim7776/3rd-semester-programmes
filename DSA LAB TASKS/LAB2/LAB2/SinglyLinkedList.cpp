#include"iostream"
#include"conio.h"
using namespace  std;

class node//struct
{
	int data;
	node *nextnodeptr;
public:
	node(int data)
	{
		this->data = data;
		nextnodeptr = NULL;
	}
	node *getNextNodeptr()
	{
		return nextnodeptr;
	}
	void  setNextNodeptr(node *nextnodeptr)
	{
		this->nextnodeptr = nextnodeptr;
	}
	int getData()
	{
		return data;
	}
	void setData(int data)
	{
		this->data = data;
	}

};



class linkedList
{
	node *header;
public:
	linkedList()
	{
		header = NULL;
	}
	bool isEmpty()
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
	int sizeOfList()
	{
		int size=0;
		node*rptr = header;
		while (rptr->getNextNodeptr() != NULL)
		{
			rptr = rptr->getNextNodeptr();
			size++;
		}
		size++;
		return size;
	}
	void insertionAtTail(node *n)
	{
		if (header == NULL)
		{
			header = n;
		}
		else
		{
			node *rptr = header;
			while (rptr->getNextNodeptr() != NULL)
			{
				rptr = rptr->getNextNodeptr();
			}
			rptr->setNextNodeptr(n);
		}

	}
	void insertionAtHead(node *n)
	{
		n->setNextNodeptr(header);
		header = n;
	}
	void insertionAtAnyPoint(node*n,int value)
	{
		node*rptr = header;
		while (rptr->getData() != value)
		{
			rptr = rptr->getNextNodeptr();
		}
		n->setNextNodeptr(rptr->getNextNodeptr());
		rptr->setNextNodeptr(n);

	}
	void display()
	{
		node *rptr = header;
		while (rptr->getNextNodeptr() != NULL)
		{
			cout << rptr->getData() << "\t";
			rptr = rptr->getNextNodeptr();
		}
		cout << rptr->getData()<<endl;
	}
	void deletionAtHead()
	{
		node*rptr = header;
		header = rptr->getNextNodeptr();
		delete rptr;
	}
	void deletionAtEnd()
	{
		node*currNode = header;
		node*prevNode = NULL;
		while (currNode->getNextNodeptr() != NULL)
		{
			prevNode = currNode;
			currNode = currNode->getNextNodeptr();
		}
		prevNode->setNextNodeptr(NULL);
		delete currNode;
	}
	void deletionAtAnyPoint(node*n)
	{
		node*currNode = header;
		node*prevNode = NULL;
		while (currNode->getData() != n->getData())
		{
			prevNode = currNode;
			currNode = currNode->getNextNodeptr();
		}
		if (currNode == header)
		{
			header = currNode->getNextNodeptr();
			delete currNode;
		}
		else
		{
			prevNode->setNextNodeptr(currNode->getNextNodeptr());
			delete currNode;

		}
	}
	void updateValue(int val, node*n)
	{
		node*rptr = header;
		while (rptr->getData() != val)
		{
			rptr = rptr->getNextNodeptr();
		}
		rptr->setData(n->getData());
	}
	int search(node*n)
	{
		int count = 0;
		node*rptr = header;
		while (rptr->getData() != n->getData())
		{
			rptr = rptr->getNextNodeptr();
			count++;
		}
		count++;
		return count;
	}
};




void main()
{
	linkedList L1;
	L1.insertionAtTail(new node(3));
	L1.insertionAtTail(new node(5));
	L1.insertionAtHead(new node(2));
	L1.insertionAtHead(new node(1));
	L1.insertionAtAnyPoint(new node(4), 3);
	L1.insertionAtTail(new node(6));
	L1.display();
	cout<<"Value 6 is available at "<<L1.search(new node(6))<<" Index\n";
	L1.deletionAtAnyPoint(new node(1));
	cout << "After deleting node with value 1\n";
	L1.display();
	L1.updateValue(5, new node(10));
	cout << "After updating node with value 5 with value 10\n";
	L1.display();
	L1.deletionAtHead();
	cout << "After deleting 1st node from Head\n";
	L1.display();
	L1.deletionAtEnd();
	cout << "After deleting from end\n";
	L1.display();
	L1.deletionAtEnd();
	cout << "After deleting from end\n";
	L1.display();
	


	_getch();
}