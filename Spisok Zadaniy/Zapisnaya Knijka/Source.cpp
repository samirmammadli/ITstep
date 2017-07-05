#include <iostream>
#include <Windows.h>
#include "Functions.h"
#include <conio.h>

#define String_Length 100
using namespace std;



void main()
{
	short def_col = 13;
	hideCursor();
	int SIZE = 4;
	short index = 0;
	int pos = 0;
	int key = 0;
	int operation = 0;
	char **list = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		list[i] = new char[String_Length] {};
	}
	strcpy(list[0], "Samir Mammadli");
	strcpy(list[1], "Kamal Jafarov");
	strcpy(list[2], "Rufat Gulabli");
	strcpy(list[3], "Vugar Yusubov");


	//
	while (true)
	{
		SIZE == 0 ? pos = SIZE : 0;

		COORDS(70, 1);
		COLORS(MAGENTA, BLACK);
		cout << "********  Tasks List  ********\n\n\n";
		COLORS(DEFAULT, BLACK);
		COORDS(70, 3);
		cout << "1. Press ";
		COLORS(RED, BLACK);
		cout << "DELETE ";
		COLORS(DEFAULT, BLACK);
		cout << "to remove the task.\n\n";
		COORDS(70, 5);
		cout << "2. Press ";
		COLORS(GREEN, BLACK);
		cout << "ENTER";
		COLORS(DEFAULT, BLACK);
		cout << " to add new task.\n";
		COORDS(70, 7);
		cout << "3. Use \"";
		COLORS(RED, BLACK);
		cout << "+";
		COLORS(DEFAULT, BLACK);
		cout << "\" or \"";
		COLORS(GREEN, BLACK);
		cout << "-";
		COLORS(DEFAULT, BLACK);
		cout << "\" to move the task up or down.\n";
		COORDS(70, 9);
		cout << "4. Press ";
		COLORS(CYAN, BLACK);
		cout << "ESCAPE";
		COLORS(DEFAULT, BLACK);
		cout << " to save and exit.\n";
		COORDS(0, def_col);

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
					cout << i + 1;
					cout << ". " << list[i] << endl;
					COLORS(DEFAULT, BLACK);
				}
				else
				{
					COLORS(CYAN, BLACK);
					cout << i + 1;
					COLORS(DEFAULT, BLACK);
					cout << ". " << list[i] << endl;
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
					pos > 0 ? pos-- : 0;
				else if (key == 80)
					pos < SIZE - 1 ? pos++ : 0;
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
			exit(0);
		}
	}
}