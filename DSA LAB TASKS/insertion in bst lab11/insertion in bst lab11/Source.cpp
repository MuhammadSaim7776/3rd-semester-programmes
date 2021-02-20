#include"BST.h"
void main()
{
	BST bst;
	bst.insertion(new BNode('d'));
	bst.insertion(new BNode('c'));
	bst.insertion(new BNode('e'));
	bst.insertion(new BNode('f'));
	bst.insertion(new BNode('b'));
	bst.insertion(new BNode('a'));
	bst.insertion(new BNode('z'));
	bst.inorder();
	bst.preoeder();
	bst.postorder();
	bst.levelorder();
	cout << "\nAfter deleting root node\n";
	bst.remove(new BNode('d'));
	bst.inorder();
	cout << "\nThe Height of tree is " << bst.height();
	_getch();
}