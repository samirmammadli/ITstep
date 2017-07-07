#include "Functions.h"

void main()
{
	srand(time(NULL));
	int row = 20, col = 40;
	int size = row * col;
	COLORS(DEFAULT, BLACK);

	int tax = 0;
	matrix **field = new matrix*[size];
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
		/*field[i]->bg = rand() % 11 + 5;
		field[i]->fg = rand() % 11 + 5;
		field[i]->symbol = rand() % 200 + 30;*/
	}
	int kursor;
	int a = 3, ax = a;
	int b = 8, bx = b;
	while (true)
	{
		for (int i = 0; i < size; i++, b++)
		{
			COORDS(a, b);
			COLORS(field[i]->fg, field[i]->bg);
			cout << field[i]->symbol;
			if ((i + 1) % col == 0)
			{
				a++;
				b = 7;
			}
		}
		COLORS(DEFAULT, BLACK);
		cout << endl;
		a = 3, b = 8;
		COORDS(ax, bx);
		kursor = getch();
		if (kursor == 224)
		{
			kursor = getch();
			if (kursor == 72)
			{
				if (ax > 3)
				{
					ax--;
				}
			}
			else if (kursor == 80)
			{
				if (ax < row + a-1)
				{
					ax++;
				}
			}
			else if (kursor == 77)
			{
				if (bx < col + b-1)
				{
					bx++;
				}
			}
			else if (kursor == 75)
			{
				if (bx > b)
					bx--;
			}
		}
	}
	

	
}