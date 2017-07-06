#include <iostream>
#include <Windows.h>
#include "Functions.h"
#include <conio.h>

#define String_Length 100
using namespace std;



void main()
{
	hideCursor();
	int SIZE = 0;
	char **list = new char*[SIZE];
	char patch[MAX_PATH];
	char temp[String_Length];
	sprintf(patch, "%s%s", getenv("USERPROFILE"), "\\Desktop\\tasks.txt");
	f = fopen(patch, "r");
	if (f != NULL && check_empty(f))
	{
		char a;
		for (int i = 0; !feof(f); i++)
		{
			init(list, SIZE, String_Length);
			for (int j = 0; j < String_Length; j++)
			{
				a = fgetc(f);
				if (a == '\n')
				{
					list[i][j] = '\0';
					break;
				}

				list[i][j] = a;
			}
		}
		fclose(f);
	}

	short def_col = 13;
	int pos = 0;
	int key = 0;

	//
	while (true)
	{
		SIZE == 0 ? pos = SIZE : 0;

		menu(list, def_col);

		COORDS(0, 2);
		if (SIZE == 0)
		{
			COLORS(CYAN, BLACK);
			cout << "There is no tasks!\n";
			COLORS(DEFAULT, BLACK);
		}
		else
		{
			COLORS(CYAN, BLACK);
			cout << "Tasks:\n";
			for (int i = 0; i < SIZE; i++)
			{
				COORDS(0, i + 4);
				if (i == pos)
				{
					COLORS(BLACK, CYAN);
					cout << i + 1 << ". ";
					COLORS(BLACK, CYAN);
					cout << list[i] << endl;
					COLORS(DEFAULT, BLACK);
				}
				else
				{
					COLORS(MAGENTA, BLACK);
					cout << i + 1 << ". ";
					COLORS(DEFAULT, BLACK);
					cout  << list[i] << endl;
				}
				if (i > 7)
					def_col = i + 6;
			}
		}
		key = getch();
		if (key == 224)
		{
			key = getch();
			{
				if (key == 72)
					pos > 0 ? pos-- : pos = SIZE-1;
				else if (key == 80)
					pos < SIZE - 1 ? pos++ : pos = 0;
				else if (key == 83)
					delete_task(list, SIZE, String_Length, pos);
			}
		}
		else if (key == 43) // +
		{
			sort_tasks(list, SIZE, String_Length, 1, pos);
		}
		else if (key == 45) // -
		{
			sort_tasks(list, SIZE, String_Length, 0, pos);
		}
		else if (key == 13) // -
		{
			add_task(list, SIZE, String_Length);
		}
		else if (key == 27) // -
		{
			save(list, SIZE, patch);
			exit(0);
		}
	}
}