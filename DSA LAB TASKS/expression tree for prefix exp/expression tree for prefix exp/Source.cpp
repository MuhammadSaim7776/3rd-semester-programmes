#include"BST.h"
void main()
{
	BST bst;
	string s = "++7*626";
	bst.insertion(s);
	bst.inorder();
	bst.preoeder();
	bst.postorder();
	_getch();
}