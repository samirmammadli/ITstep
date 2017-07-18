#include "Functions.h"

FILE *f;

void load_matrix(matrix **&field, int size, FILE* f)
{
	f = fopen("file.bin", "rb");
	if (f != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fread(field[i], sizeof(matrix), 1, f);
		}
		fclose(f);
	}
}





void main()
{
	
	system("color 17");
	srand(time(NULL));
	short top_up = 2;
	short top_left = 5;
	int row = 20, col = 55;
	int size = row * col;
	char curr_symb = '.' ;
	char menu[][50] = {
		"Press F1 to '.'",
		"Press F2 to '+'",
		"Press F3 to '*'",
		"Press F4 to '-'",
		"Press F5 to '_'",
		"Press F6 to '@'",
		"Press ESCAPE to Save",
		"Press DEL to Erase All",
		"Red",
		"Green",
		"Yellow",
		"White",
		"Black",
		"Blue"
	};
	
	print_menu(menu, top_up, top_left, col);


	matrix **field = new matrix*[size];
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
	}

	load_matrix(field, size, f);
	
	int index = 0;
	
	int a = 0, ax = a;
	int b = 0, bx = b;
	while (true)
	{
		hideCursor(false);
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
		
		control(field, ax, bx, index, row, col, size, curr_symb, f);

		COLORS(DEFAULT, BLACK);
	}
}