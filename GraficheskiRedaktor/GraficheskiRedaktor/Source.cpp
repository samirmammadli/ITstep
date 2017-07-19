#include "Functions.h"

FILE *f;

void main()
{
	
	system("color 17");
	srand(time(NULL));
	short top_up = 2;
	short top_left = 5;
	int row = 20, col = 55;
	char curr_symb = '.' ;
	char menu[][50] = {
		"Press F1 to '.'",
		"Press F2 to '+'",
		"Press F3 to '*'",
		"Press F4 to '@'",
		"Press F5 to '_'",
		"Press F6 to '-'",
		"Press BACKSPACE to delete symbol",
		"Press DEL to Erase All",
		"Press ESCAPE to Save",
		"White",
		"Green",
		"Yellow",
		"Red",
		"Black",
		"Blue"
	};
	
	print_menu(menu, top_up, top_left, col);


	matrix **field = new matrix*[row];
	for (int i = 0; i < row; i++)
	{
		field[i] = new matrix[col];
	}

	load_matrix(field, row, col, f);
	
	
	int ax = 0;
	int bx = 0;
	while (true)
	{
		hideCursor(false);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				/*field[i][j].fg = rand() % 2 + 4;
				field[i][j].bg = rand() % 2 + 4;*/
				COORDS(i + top_up, j + top_left);
				i == ax && j == bx ? COLORS(field[i][j].fg, DARKGREY) : COLORS(field[i][j].fg, field[i][j].bg);
				cout << field[i][j].symbol;
			}
		}
		COLORS(DEFAULT, DARKBLUE);
		control(field, ax, bx, row, col, curr_symb, f);
	}
}