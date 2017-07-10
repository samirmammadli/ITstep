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
	
	int a = 0, ax = top_up;
	int b = 0, bx = top_left;
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
			COORDS(short(a + top_up), short(b + top_left));
			COLORS(field[i]->fg, field[i]->bg);
			cout << field[i]->symbol;
			
		}
		COLORS(DEFAULT, BLACK);
		cout << endl;
		a = 0, b = 0;
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
				if (ax < row + top_up - 1)
				{
					ax++;
					index += col;
				}
			}
			else if (key == 77)
			{
				if (bx < col + top_left - 1)
				{
					bx++;
					index++;
				}
			}
			else if (key == 75)
			{
				if (bx > top_left)
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
			
			if (bx > top_left)
			{
				bx--;
				index--;
				field[index]->symbol = ' ';
			}

		}
		/*else if (key == 13)
		{
			if (ax < row + top_up - 1)
			{
				ax++;
				index = bx - bx % col;
				bx = top_left;
			}
		}*/
		else 
		{
			field[index]->symbol = key;
			if (bx < col + top_left - 1)
			{
				bx++;
				index++;
			}
		}
	}



}