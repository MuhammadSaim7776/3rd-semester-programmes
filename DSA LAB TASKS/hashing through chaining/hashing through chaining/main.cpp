#include"Node.h"
#include"Hash.h"
void main()
{
	Hash tab(10);
	tab.insert(new Node(10));
	tab.insert(new Node(20));
	tab.insert(new Node(30));
	tab.insert(new Node(11));
	tab.insert(new Node(12));
	tab.insert(new Node(13));
	tab.insert(new Node(14));
	tab.insert(new Node(15));
	tab.insert(new Node(9));
	tab.insert(new Node(8));
	tab.insert(new Node(7));
	tab.insert(new Node(87));
	tab.insert(new Node(93));
	tab.insert(new Node(22));
	tab.insert(new Node(560));
	tab.insert(new Node(482));
	tab.insert(new Node(951));
	tab.insert(new Node(271));
	tab.display();
	int i = tab.search(new Node(20));
	if ( i== -1)
	{
		cout << "Element not found\n";
	}
	else
	{
		cout << "Element found at index " << i << endl;
	}
	tab.remove(new Node(560));
	tab.remove(new Node(10));
	cout << "After deleting elements\n";
	tab.display();
	_getch();
}