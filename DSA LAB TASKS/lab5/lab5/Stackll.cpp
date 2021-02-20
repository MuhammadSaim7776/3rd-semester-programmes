#include <iostream>
#include<conio.h>
using namespace std;
// stack using linklist
class Node {
private:
	int	data;		// data
	Node* next;		// pointer to next
public:
	Node(int x)
	{
		data = x;
		next = NULL;
	}
	void setData(int x)
	{
		data = x;
	}
	int getData()const
	{
		return data;
	}
	void setNextPtr(Node*n)
	{
		next = n;
	}
	Node*getNextPtr()const
	{
		return next;
	}
};

class Stack {
private:
	Node*head;
public:
	Stack() // constructor
	{
		head = NULL;
	}
	~Stack()
	{
	}// destructor
	void push(Node*);
	void pop();
	int top();
	bool isEmpty();
	void display()const;
};
void Stack::pop()
{
	if (head == NULL)
	{
		cout << "Stack is empty\n";
	}
	// delete the first element
	else
	{
		Node* temp = head;
		if (temp->getNextPtr() == NULL)
		{
			head = NULL;
			delete temp;
			cout << "1st Node deleted successfully!!!\n";
		}
		else
		{
			head = head->getNextPtr();
			delete temp;
			cout << "1st Node deleted successfully!!!\n";
		}
		
	}
}
void Stack::push(Node*N)
{
	Node*temp = head;
	if (head == NULL)
	{
		head = N;
		cout << "Node inserted successfully!!\n";
	}
	else
	{
		N->setNextPtr(head);
		head = N;
		cout << "Node inserted successfully!!\n";
	}
}
int Stack::top()
{
	return head->getData();
}
bool Stack::isEmpty()
{
	return (head == NULL);
}
void Stack::display()const
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
//main driver program
void main() {
	Stack stack;
	stack.push(new Node(10));
	stack.push(new Node(20));
	stack.push(new Node(30));
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();
	_getch();
}