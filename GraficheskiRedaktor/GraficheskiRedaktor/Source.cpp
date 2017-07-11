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
	short top_up = 5;
	short top_left = 15;
	int row = 15, col = 20;
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
	
	int a = 0, ax = a;
	int b = 0, bx = b;
	while (true)
	{
		hideCursor();
		for (int i = 0; i < size; i++, b++)
		{
			if (i % col == 0 && i !=0)
			{
				a++;
				b = 0;
			}
			COORDS(a+top_up, b+top_left);
			COLORS(field[i]->fg, field[i]->bg);
			cout << field[i]->symbol;
			
		}
		COLORS(DEFAULT, BLACK);
		cout << endl;
		a = 0, b = 0;
		COORDS(ax+top_up, bx+top_left);
		hideCursor(true);
		//cout << ax << endl;
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72)
			{
				if (ax > 0)
				{
					ax--;
					index -= col;
				}
			}
			else if (key == 80)
			{
				if (ax < row - 1)
				{
					ax++;
					index += col;
				}
			}
			else if (key == 77)
			{
				if (bx < col - 1)
				{
					bx++;
					index++;
				}
			}
			else if (key == 75)
			{
				if (bx > 0)
				{
					bx--;
					index--;
				}
			}
			else if (key == 83)
			{
				field[index]->symbol = ' ';
			}
		}
		else if (key == 8)
		{
			
			if (bx > b)
			{
				bx--;
				index--;
				field[index]->symbol = ' ';
			}

		}
		else if (key == 13)
		{
			if (ax < row + a - 1)
			{
				ax++;
				index = ax*col;
				bx = 0;
			}
		}
		else 
		{
			field[index]->symbol = key;
			if (bx < col + b - 1)
			{
				bx++;
				index++;
			}
		}
	}



}