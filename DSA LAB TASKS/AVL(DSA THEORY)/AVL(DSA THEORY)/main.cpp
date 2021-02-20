#include"AVLTree.h"
using namespace std;
void main()
{
	AVLTree tree;
	tree.AVLinsert(new AVLNode(1));
	tree.AVLinsert(new AVLNode(2));
	tree.AVLinsert(new AVLNode(3));
	tree.AVLinsert(new AVLNode(4));
	tree.AVLinsert(new AVLNode(5));
	tree.AVLinsert(new AVLNode(6));
	tree.AVLinsert(new AVLNode(7));
	tree.AVLinsert(new AVLNode(16));
	tree.AVLinsert(new AVLNode(15));
	tree.AVLinsert(new AVLNode(14));
	tree.AVLinsert(new AVLNode(13));
	/*tree.AVLinsert(new AVLNode(12));
	tree.AVLinsert(new AVLNode(13));*/
	tree.levelorder();
	/*cout << "Elements after deletion\n";
	tree.remove(new AVLNod*//*e(9));*/
	/*tree.levelorder();*/
	_getch();
}