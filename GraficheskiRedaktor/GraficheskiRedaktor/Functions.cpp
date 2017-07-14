#include "Functions.h"

void print_menu(char menu[][50], short top_up, short top_left, int col)
{
	top_left += 5 + col;
	COORDS(top_up -2, top_left);
	cout << "************************************";
	COORDS(top_up - 1, top_left);
	cout << "*************** Menu ***************";

	for (short i = 0; i < 8; i++)
	{
		COORDS(top_up + i, top_left);
		printf("** %-31s", menu[i]);
		cout << "**";
		if (i == 7)
		{
			COORDS(top_up + i + 1, top_left);
			cout << "************************************";
			COORDS(top_up + i + 2, top_left);
			cout << "************************************";
		}
	}
}

void vipe_matrix(matrix **field, int size)
{
	for (int i = 0; i < size; i++)
	{
		field[i] = new matrix;
	}
}

void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}