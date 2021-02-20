#include "cStack.h"


cStack::cStack()
{
	top = -1;

}
bool cStack::push(string x)
{
	if (top>=MAXSIZE-1)
	{
		cout << "Stack overflow"<<endl;
		return false;
	}
	else
	{
		stringStack[++top] = x;
		cout << "Pushed: " << x << endl;
		return true;

	}

}
string cStack::pop()
{
	if (top<0)
	{
		cout << "Stack Underflow" << endl;
		return "";

	}
	else
	{
		string item = stringStack[top--];
		cout << "item removed is: " << item << endl;
		return item;

	}

}
string cStack::mtop()
{

	return stringStack[top];
}
bool cStack::isFull()
{

	if (top == (MAXSIZE - 1))
		return true;
	else
		return false;
}
bool cStack::isEmpty()
{

	return (top<0);
}
void cStack::displayReverse()
{
	
	cout << "Elements in stack are\n";
	for (int i = top; i>=0;i--)
	{
		cout << stringStack[i] << "\t";
	}
	cout << endl;
}


cStack::~cStack()
{
}
