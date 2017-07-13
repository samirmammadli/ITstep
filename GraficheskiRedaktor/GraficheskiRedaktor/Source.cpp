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
	short top_up = 2;
	short top_left = 5;
	int row = 25, col = 75;
	int size = row * col;
	char menu[8][50] = {
		"1. Press DEL to Erase All",
		"2. Something",
		"3. Something",
		"4. Something",
		"5. Something",
		"6. Something",
		"7. Something",
		"8. Something",
	};
	
	print_menu(menu, top_up, top_left, col);


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
			a == ax && b == bx ? COLORS(field[i]->fg, DARKGREY) : COLORS(field[i]->fg, field[i]->bg);
			cout << field[i]->symbol;
			
		}
		cout << endl;
		a = 0, b = 0;
		COORDS(ax+top_up, bx+top_left);
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
				vipe_matrix(field, size);
				ax = 0, bx = 0, index = 0;
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
		COLORS(DEFAULT, BLACK);
	}
}