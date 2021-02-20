#include"point.h"
#include"snake.h"
#include<windows.h>
#include<conio.h>
#include"Food.h"
#include<ctime>
snake Snake(new Node(width / 2, height / 2), 1);
Food food;

void board()
{
	point headpos = Snake.get_position();
	for (int i = 0; i < height; i++)
	{
		cout << "\t\t#";
		for (int j = 0; j < width - 2; j++)
		{
			if (i == 0 || i == height - 1)
			{
				cout << "#";
			}
			else if (j+1 == headpos.get_X() && i == headpos.get_Y())
			{
				cout << 0;
			}
			else if (j+1 == food.get_foodX() && i == food.get_foodY())
			{
				cout << "@";
			}
			else
			{
				/*cout << " ";*/
				bool part = false;
				Node*rptr = Snake.return_head();
				while (rptr->get_next() != NULL)
				{
					if (i == rptr->get_Y() && j + 1 == rptr->get_X())
					{
						cout << "o";
						part = true;
						break;
					}
					
				}
				if (part == false)
				{
					cout << " ";
				}
			}	
		}
		cout << "#\n";
	}
}
void main()
{
	srand(time(NULL));
	food.gen_food();
	while (Snake.collision()!=true)
	{
		board();
		if (_kbhit())
		{
			switch (_getch())
			{
			case'w':
				Snake.turnUp();
				break;
			case's':
				Snake.turnDown();
				break;
			case'd':
				Snake.turnRight();
				break;
			case'a':
				Snake.turnLeft();
				break;

			}
		}
		if (Snake.eatenFoodOrNot(food.get_foodPossition())==true)
		{
			food.gen_food();
			Snake.grow();
		}
		Snake.move();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
	
	_getch();
}