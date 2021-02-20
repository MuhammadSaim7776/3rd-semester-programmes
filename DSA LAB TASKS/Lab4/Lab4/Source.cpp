//#include <iostream>
//#include<string>
//#include<conio.h>
//using namespace std;
//#define MAXSIZE 3 
//
//class CStack
//{
//private:
//	int top;
//public:
//	string stringStack[MAXSIZE]; 
//	CStack() // constructor
//	{
//		top = -1;
//
//	}
//	bool push(string x);
//	string pop();
//	string mtop();
//	bool isFull();
//	bool isEmpty();
//	void displayReverse();
//	
//};
//bool CStack::push(string x)
//{
//	if (top>=MAXSIZE-1)
//	{
//		cout << "Stack overflow"<<endl;
//		return false;
//	}
//	else
//	{
//		integerStack[++top] = x;
//		cout << "Pushed: " << x << endl;
//		return true;
//
//	}
//
//}
//string CStack::pop()
//{
//	if (top<0)
//	{
//		cout << "Stack Underflow" << endl;
//		return "";
//
//	}
//	else
//	{
//		string item = integerStack[top--];
//		cout << "item removed is: " << item << endl;
//		return item;
//
//	}
//
//}
//string CStack::mtop()
//{
//
//	return integerStack[top];
//}
//bool CStack::isFull()
//{
//
//	if (top == (MAXSIZE - 1))
//		return true;
//	else
//		return false;
//}
//bool CStack::isEmpty()
//{
//
//	return (top<0);
//}
//void CStack::displayReverse()
//{
//	
//	cout << "Elements in stack are\n";
//	for (int i = top; i>=0;i--)
//	{
//		cout << integerStack[i]<<"\t";
//	}
//	cout << endl;
//}
//
//void main() {
//	CStack mystack;
//
//	mystack.push("Islamabad");
//	mystack.push("lahore");
//	mystack.push("Karachi");
//	mystack.push("KPK");
//	cout << "Top Element on Stack is: " << mystack.mtop() << endl;
//	mystack.displayReverse();
//	mystack.pop();
//	mystack.pop();
//	mystack.pop();
//	mystack.pop();
//	_getch();
//
//}