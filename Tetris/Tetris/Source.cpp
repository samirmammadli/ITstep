#include "Functions.h"


void hideCursor(bool switch_cursor = false)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}


void main()
{



	srand(time(NULL));
	int top_up = 5;
	int top_left = 15;
	int row = 30, col = 35;
	int size = row * col;
	COLORS(DEFAULT, BLACK);

	matrix **field = new matrix*[size];
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
		/*field[i]->bg = rand() % 11 + 5;
		field[i]->fg = rand() % 11 + 5;
		field[i]->symbol = rand() % 200 + 30;*/
	}

	int key, index = 0;
	
	int a = top_up, ax = a;
	int b = top_left, bx = b;
	while (true)
	{
		hideCursor();
		for (int i = 0; i < size; i++, b++)
		{
			if (i % col == 0 && i !=0)
			{
				a++;
				b = top_left;
			}
			COORDS(a, b);
			COLORS(field[i]->fg, field[i]->bg);
			cout << field[i]->symbol;
			
		}
		COLORS(DEFAULT, BLACK);
		cout << endl;
		a = top_up, b = top_left;
		COORDS(ax, bx);
		hideCursor(true);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72)
			{
				if (ax > top_up)
				{
					ax--;
					index -= col;
				}
			}
			else if (key == 80)
			{
				if (ax < row + a - 1)
				{
					ax++;
					index += col;
				}
			}
			else if (key == 77)
			{
				if (bx < col + b - 1)
				{
					bx++;
					index++;
				}
			}
			else if (key == 75)
			{
				if (bx > b)
				{
					bx--;
					index--;
				}
			}
		}
		else
		{
			field[index]->symbol = key;
		}
	}
}