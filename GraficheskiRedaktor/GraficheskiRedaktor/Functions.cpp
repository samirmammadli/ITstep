#include "Functions.h"

void print_menu(char menu[][50], short top_up, short top_left, int col)
{
	short top_menu = top_up + 2;
	top_left += 5 + col;
	COORDS(top_menu - 2, top_left);
	cout << "************************************";
	COORDS(top_menu - 1, top_left);
	cout << "************* Symbols **************";

	for (short i = 0; i < 8; i++)
	{
		COORDS(top_menu + i, top_left);
		printf("**      %-26s", menu[i]);
		cout << "**";
		if (i == 7)
		{
			COORDS(top_menu + i + 1, top_left);
			cout << "************************************";
			COORDS(top_menu + i + 2, top_left);
			cout << "************************************";
		}
	}
}

void write_matrix(matrix **field, int size, FILE *f)
{
	f = fopen("file.bin", "wb");
	for (int i = 0; i < size; i++)
	{
		fwrite(field[i], sizeof(matrix), 1, f);
	}
	fclose(f);
}


void vipe_matrix(matrix **field, int size)
{
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
	}
}



void control(matrix **&field, int &ax, int &bx, int &index, int row, int col, int size, char &curr_symb, FILE* f)
{
	int key = getch();

	//Cursor Position
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
		//Wipe all symbols
		else if (key == 83)
		{
			vipe_matrix(field, size);
			ax = 0, bx = 0, index = 0;
		}
	}

	//Select Symbol
	else if (key == 0)
	{
		key = getch();
		if (key == 59)
		{
			curr_symb = '.';
		}
		else if (key == 60)
		{
			curr_symb = '+';
		}
		else if (key == 61)
		{
			curr_symb = '*';
		}
		else if (key == 62)
		{
			curr_symb = '-';
		}
		else if (key == 63)
		{
			curr_symb = '_';
		}
		else if (key == 64)
		{
			curr_symb = '@';
		}
	}

	//Delete symbol
	else if (key == 8)
	{

		if (bx > 0)
		{
			field[index]->symbol = ' ';
			bx--;
			index--;
		}
		else
			field[index]->symbol = ' ';

	}

	//Input Symbol
	else if (key == 13)
	{
		field[index]->symbol = curr_symb;
	}

	//Exit Program and Save file
	else if (key == 27)
	{
		write_matrix(field, size, f);
		exit(0);
	}




	//COORDS(top_menu + 11, top_left);
	//cout << "**** Press TAB to select Color *****";
	//COORDS(top_menu + 12, top_left);
	//cout << "Foreground: ";
	//for (short i = 8; i < 14; i++)
	//{
	//	//COORDS(top_menu + i + 5, top_left);
	//	cout << menu[i] << "   ";
	//}
}



void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

