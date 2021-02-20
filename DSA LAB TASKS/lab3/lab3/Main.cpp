#include"Node.h"
#include"List.h"
void main()
{
	List L1;
	L1.insertionAtTail(new Node('A'));
	L1.insertionAtTail(new Node('B'));
	L1.insertionAtTail(new Node('C'));
	L1.insertionAtTail(new Node('E'));
	L1.insertionAtTail(new Node('F'));
	L1.insertionAtHead(new Node('X'));
	L1.insertionAtAnyPoint(new Node('D'), new Node('A'));
	cout << "The Data in the List is as follow\n";
	L1.display();
	cout << "The size of list is " << L1.sizeOfList() << endl;
	cout << L1.isEmpty()<<endl;
	L1.deletionAtHead();
	cout << "After deleting data from start List is as follow\n";
	L1.display();
	L1.deletionAtEnd();
	cout << "After deleting data from end List is as follow\n";
	L1.display();
	/*L1.deletionAtAnyPoint(new Node('X'));
	cout << "After deleting data of node having value X List is as follow\n";
	L1.display();*/
	cout << "searching value A in List\t" << L1.search(new Node('X'));
	/*cout << "The Data in the List in reverse order is as follow\n";
	L1.displayreverse();*/
	_getch();
}