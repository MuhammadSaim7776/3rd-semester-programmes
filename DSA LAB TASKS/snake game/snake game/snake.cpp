#include "snake.h"


snake::snake(Node*n,int v)
{
	head = n;
	velocity = v;
	dir = 'n';
	length = 1;
}
void snake::increase_Size(Node* node)
{
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		node->set_Next(head);
		head = node;
	}
	
}
int snake::snake_size()
{
	int size = 0;
	Node*rptr = head;
	while (rptr != NULL)
	{
		size++;
	}
	return size;
}
void snake::decrease_size()
{
	Node*rptr = head;
	Node*hptr = NULL;
	while (rptr->get_next() != NULL)
	{
		hptr = rptr;
		rptr = rptr->get_next();
	}
	hptr->set_Next(NULL);
	delete rptr;
}
//void snake::display_Snake()
//{
//	Node*rptr = head;
//	while (rptr != NULL)
//	{
//		cout << "*";
//		rptr = rptr->get_next();
//	}
//}
void snake::turnUp()
{
	dir = 'w';//w is a control key to move snake upward;
}
void snake::turnDown()
{
	dir = 's';//s is a control key to move snake downward;
}
void snake::turnLeft()
{
	dir = 'd';//d is a control key to move snake left;
}
void snake::turnRight()
{
	dir = 'a';//w is a control key to move snake right;
}
void snake::move()
{
	switch (dir)
	{
	case'w':
		head->data.Move_Up(velocity);
		break;
	case's':
		head->data.Move_Down(velocity);
		break;
	case'd':
		head->data.Move_Left(velocity);
		break;
	case'a':
		head->data.Move_Right(velocity);
		break;
	}
	/*increase_Size(new Node(pos.get_X(), pos.get_Y()));
	if (snake_size() > length)
	{
		decrease_size();
	}*/

}
point snake::get_position()
{
	return head->data;
}
bool snake::eatenFoodOrNot(point food)
{
	if (head->get_X() == food.get_X() && head->get_Y() == food.get_Y())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void snake::grow()
{
	length++;
}
bool snake::collision()
{
	if (head->get_X()<1 || head->get_X()>48 || head->get_Y()<1 || head->get_Y()>23)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Node*snake::return_head()
{
	return head;
}
snake::~snake()
{
}
