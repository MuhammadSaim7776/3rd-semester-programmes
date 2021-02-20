#include "Stack.h"


AVLNode* Stack::pop()
{
	if (head == NULL)
	{
		cout << "Stack is empty\n";
		return NULL;
	}
	// delete the first element
	else
	{
		SNode* temp = head;
		AVLNode*t = NULL;
		if (temp->getNextPtr() == NULL)
		{
			t = temp->getData();
			head = NULL;
			delete temp;	
			/*cout << "1st Node deleted successfully!!!\n";*/
		}
		else
		{
			t = temp->getData();
			head = head->getNextPtr();
			delete temp;
			/*cout << "1st Node deleted successfully!!!\n";*/
		}
		return t;
	}
}
void Stack::push(SNode*N)
{
	SNode*temp = head;
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
AVLNode* Stack::top()
{
	return head->getData();
}
bool Stack::isEmpty()
{
	return (head == NULL);
}
void Stack::display()const
{
	SNode*temp = head;
	if (temp == NULL)
	{
		cout << "Stack is empty!!!!\n";
	}
	else
	{
		while (temp->getNextPtr() != NULL)
		{
			cout << temp->getData()->get_data() << "\t";
			temp = temp->getNextPtr();
		}
		cout << temp->getData()->get_data() << "\n";

	}
}