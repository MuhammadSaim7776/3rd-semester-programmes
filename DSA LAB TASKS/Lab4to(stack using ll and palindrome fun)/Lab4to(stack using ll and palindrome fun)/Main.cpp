#include"Stack.h"
#include<string>
#include<math.h>
bool palindromeOrNot(string n)
{
	int length = n.length();
	int mid = length/2;
	Stack stack;
	for (int i = 0; i < mid; i++)
	{
		stack.push(new Node(n[i]));
	}
	if (length % 2 == 1)
	{
		for (int i = mid; i < length-1; i++)
		{
			if (stack.top() == n[i+1])
			{
				stack.pop();
			}
			else
			{
				break;
			}
		}
		if (stack.isEmpty()==true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		for (int i = mid; i < length; i++)
		{
			if (stack.top() == n[i])
			{
				stack.pop();
			}
			else
			{
				break;
			}
		}
		if (stack.isEmpty()==true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void reverseString(string n)
{
	Stack stack;
	for (int i = 0; i < n.length(); i++)
	{
		stack.push(new Node(n[i]));
	}
	stack.display();
}
void main() 
{
	string Data = "";
	cout << "Enter the string that you want to check if it is palindrome or not\n";
	cin >> Data;
	if (palindromeOrNot(Data) == true)
	{
		cout << Data << " is palindrome\n";
	}
	else
	{
		cout << Data << " is not palindrome\n";
	}	
	cout << "Given string in reverse order is\n";
	reverseString(Data);
	_getch();

}


