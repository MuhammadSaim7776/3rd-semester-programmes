#include "Hash.h"
#include<math.h>


Hash::Hash(int capacity)
{
	this->capacity = capacity;
	Table = new Node*[capacity]{};
	for (int i = 0; i < capacity; i++)
	{
		Table[i] = NULL;
	}
}
void Hash::decTOBin(int number)
{
	int i = 0;
	int num = number;
	int rem = 0;
	while (num != 0)
	{
		rem = num % 2;
		num = num / 2;
		arr[i] = rem;
		i++;
	}
}
int Hash::hash()
{
	int dec = 0;
	for (int i = 0; i < 4; i++)
	{
		dec += arr[i] * pow(2, i);
	}
	return dec%capacity;
}
void Hash::reset_indices()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = 0;
	}
}
void Hash::insert(Node* n)
{
	int index = 0;
	reset_indices();
	decTOBin(n->get_Data());
	index = hash();
	if (Table[index] == NULL)
	{
		Table[index] = n;
	}
	else
	{
		Node*rptr = Table[index];
		n->set_Next(rptr);
		Table[index] = n;
	}

}
int Hash::search(Node*n)
{
	reset_indices();
	decTOBin(n->get_Data());
	int index = hash();
	if (Table[index] != NULL)
	{
		if (Table[index]->get_Data() == n->get_Data())
		{
			return index;
		}
		else
		{
			Node*ptr = Table[index];
			while (ptr != NULL&&ptr->get_Data() != n->get_Data())
			{
				ptr = ptr->get_Next();
			}
			if (ptr != NULL)
			{
				return index;
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		cout << "Element doesnot exist\n";
		return -1;
	}	
}
void Hash::remove(Node*n)
{
	int index = search(n);
	if (index == -1)
	{
		cout << "Element not found!!!!!\n";
	}
	else
	{
		Node*ptr = Table[index];
		Node*parent = NULL;
		if (Table[index]->get_Data() == n->get_Data())
		{
			Table[index] = Table[index]->get_Next();
		}
		else
		{
			while (ptr != NULL&&ptr->get_Data() != n->get_Data())
			{
				parent = ptr;
				ptr = ptr->get_Next();
			}
			if (ptr != NULL)
			{
				parent->set_Next(ptr->get_Next());
				ptr->set_Next(NULL);
				cout << ptr->get_Data() << " is deleted seccuessfully\n";
				delete ptr;
			}
			else
			{
				cout << "Element not found!!!!!\n";
			}
		}	
	}
}
void Hash::display()
{
	Node**rptr = Table;
	Node*ptr = NULL;
	for (int i = 0; i < capacity; i++)
	{
		cout << i << "-->";
		if (Table[i] != NULL)
		{
			ptr = Table[i];
			if (ptr != NULL)
			{
				while (ptr != NULL)
				{
					cout << ptr->get_Data() << "\t";
					ptr = ptr->get_Next();
				}
			}
		}
		cout << endl;
	}
}
Hash::~Hash()
{
}
