#include"cStack.h"
void main() {
	cStack mystack;
	mystack.push("Islamabad");
	mystack.push("lahore");
	mystack.push("Karachi");
	mystack.push("KPK");
	cout << "Top Element on Stack is: " << mystack.mtop() << endl;
	mystack.displayReverse();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	_getch();

}