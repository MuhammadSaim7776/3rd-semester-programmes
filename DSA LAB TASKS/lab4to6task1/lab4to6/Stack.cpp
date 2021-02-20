#include "Stack.h"


Stack::Stack()
{
	head = NULL;
}
void Stack::pop()
{
	if (head == NULL)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		Node* temp = head;
		if (temp->getNextPtr() == NULL)
		{
			head = NULL;
			delete temp;
			/*cout << "1st Node deleted successfully!!!\n";*/
		}
		else
		{
			head = head->getNextPtr();
			delete temp;
			/*cout << "1st Node deleted successfully!!!\n";*/
		}

	}
}
void Stack::push(Node*N)
{
	Node*temp = head;
	if (head == NULL)
	{
		head = N;
		/*cout << "Node inserted successfully!!\n";*/
	}
	else
	{
		N->setNextPtr(head);
		head = N;
		/*cout << "Node inserted successfully!!\n";*/
	}
}
char Stack::top()
{
	return head->getData();
}
bool Stack::isEmpty()
{
	return (head == NULL);
}
void Stack::display()
{
	cout << "The Elements in the Stack according to LIFO method are\n";
	Node*temp = head;
	if (temp == NULL)
	{
		cout << "Stack is empty!!!!\n";
	}
	else
	{
		while (temp->getNextPtr() != NULL)
		{
			cout << temp->getData() << "\t";
			temp = temp->getNextPtr();
		}
		cout << temp->getData() << "\n";

	}
}



Stack::~Stack()
{
}
