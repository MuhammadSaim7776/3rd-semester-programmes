#include"Node.h"
#include"Stack.h"
#include<string>
int precedence(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool accociativity(char c)
{
	if (c == '+', c == '-', c == '*', c == '/')
	{
		return true;
	}
	else if (c == '^')
	{
		return false;
	}
}
void main()
{
	Stack List;
	string pExp = "";
	string input = "a+b*(c^d-e)^(f+g*h)-i";
	/*cout << "Enter the Infix expresion\n";
	cin >> input;*/
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a'&&input[i] <= 'z' || input[i] >= 'A'&&input[i] <= 'Z')
		{
			pExp += input[i];
		}
		else if (input[i] == '(')
		{
			List.push(new Node('('));
		}
		else if (input[i] == ')')
		{
			while (List.top() != '('&&List.isEmpty() != true)
			{
				pExp += List.top();
				List.pop();
			}
			if (List.top() == '(')
			{
				List.pop();
			}
		}
		else
		{
			if (List.isEmpty() == true || precedence(input[i]) > precedence(List.top()) || List.top() == '(')
			{
				List.push(new Node(input[i]));
			}
			else if (precedence(input[i]) == precedence(List.top()))
			{
				if (accociativity(input[i] == false))
				{
					List.push(new Node(input[i]));
				}
				else
				{
					while (List.isEmpty() != true && accociativity(List.top()) != false)
					{
						pExp += List.top();
						List.pop();
					}
					List.push(new Node(input[i]));
				}
			}
			else
			{
				while (List.isEmpty() != true && List.top() != '(' && precedence(input[i]) <= precedence(List.top()))
				{
					pExp += List.top();
					List.pop();
				}
				List.push(new Node(input[i]));
				if (List.top() == '(')
				{
					List.pop();
				}
			}
		}

	}
	while (List.isEmpty() != true)
	{
		pExp += List.top();
		List.pop();
	}
	List.display();
	cout << endl;
	cout << "The given infix expresion in post fix form is as follow\n" << pExp;
	_getch();
}

/*while (List.isEmpty() != true && precedence(input[i]) <= precedence(List.top()))
{
pExp += List.top();
List.pop();

}
List.push(new Node(input[i]));*/