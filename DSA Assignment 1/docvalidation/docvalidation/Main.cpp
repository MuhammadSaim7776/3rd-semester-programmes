#include"Stack.h"
#include<fstream>
void main()
{
	string file="";
	string nodeData = "";
	fstream myfile;
	Stack stack;
	bool status = false;
	myfile.open("HTML.txt");
	myfile >> file;
	char*arr = new char[file.length()];
	for (unsigned i = 0; i < file.length(); i++)
	{
		arr[i] = file[i];
	}
	arr[file.length()] = 'A';
	while (*arr != 'A')
	{
		if (*arr == '<')
		{
			arr++;
			if (*arr != '/')
			{
				if (*arr == '>')
				{
					cout << "Empty tags are not allowed!!!!\n";
					status = true;
					break;
				}
				else
				{
					nodeData.clear();
					while (*arr != '>')
					{
						nodeData = nodeData + *arr;
						arr++;
					}
					stack.push(new Node(nodeData));
				}
			}
			else
			{
				arr++;
				nodeData.clear();
				while (*arr != '>')
				{
					nodeData = nodeData + *arr;
					arr++;
				}
				if (stack.isEmpty() == true)
				{
					cout << "1st tag is closing tag. That is not permissible!!!!!\n";
					status = true;
					break;
					
				}
				else
				{
					if (stack.top() == nodeData)
					{
						stack.pop();
					}
					else
					{
						continue;
						status = true;
						break;
					}
				}
			}			
		}
		else
		{
			arr++;
		}
	}
	if (status==false&&stack.isEmpty() == true )
	{

			cout << "Valid HTML Document!\n";
		
	}
	else
	{
		cout << "Document is invalid!!!!!\n";
	}
	myfile.close();
	_getch();
	
}