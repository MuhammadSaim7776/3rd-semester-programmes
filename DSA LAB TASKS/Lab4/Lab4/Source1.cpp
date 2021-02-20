#include <iostream>
#include<string>
#include<conio.h>
using namespace std;
#define MAXSIZE 3 

class CStack
{
private:
	int top;
public:
	int integerStack[MAXSIZE]; 
	CStack() 
	{
		top = -1;

	}
	bool push(int x);
	int pop();
	int mtop();
	bool isFull();
	bool isEmpty();
	void displayReverse();

};
bool CStack::push(int x)
{
	if (top >= MAXSIZE - 1)
	{
		cout << "Stack overflow" << endl;
		return false;
	}
	else
	{
		integerStack[++top] = x;
		cout << "Pushed: " << x << endl;
		return true;

	}

}
int CStack::pop()
{
	if (top<0)
	{
		cout << "Stack Underflow" << endl;
		return 0;

	}
	else
	{
		int item = integerStack[top--];
		cout << "item removed is: " << item << endl;
		return item;

	}

}
int CStack::mtop()
{

	return integerStack[top];
}
bool CStack::isFull()
{

	if (top == (MAXSIZE - 1))
		return true;
	else
		return false;
}
bool CStack::isEmpty()
{

	return (top<0);
}
void CStack::displayReverse()
{

	cout << "Elements in stack are\n";
	for (int i = top; i >= 0; i--)
	{
		cout << integerStack[i] << "\t";
	}
	cout << endl;
}

void main() {
	CStack mystack;

	mystack.push(10);
	mystack.push(20);
	mystack.push(30);
	mystack.push(40);
	cout << "Top Element on Stack is: " << mystack.mtop() << endl;
	mystack.displayReverse();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	_getch();

}