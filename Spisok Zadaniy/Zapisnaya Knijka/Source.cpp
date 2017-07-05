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
		COORDS(80, 1);
		COLORS(MAGENTA, BLACK);
		cout << "*****\t\tTasks List\t\t*****\n\n\n";
		COLORS(DEFAULT, BLACK);
		COORDS(80, 3);
		cout << "1. Press ";
		COLORS(RED, BLACK);
		cout << "DELETE ";
		COLORS(DEFAULT, BLACK);
		cout << "to remove the task.\n\n";
		COORDS(80, 5);
		cout << "2. Use \"";
		COLORS(RED, BLACK);
		cout << "+";
		COLORS(DEFAULT, BLACK);
		cout << "\" or \"";
		COLORS(GREEN, BLACK);
		cout << "-";
		COLORS(DEFAULT, BLACK);
		cout << "\" to move the task up or down.\n";
		COORDS(80, 7);
		cout << "3. Press ";
		COLORS(CYAN, BLACK);
		cout << "ESCAPE";
		COLORS(DEFAULT, BLACK);
		cout << " to save and exit.\n";
		COORDS(0, def_col);

		disp_list(list, SIZE, def_col, pos);


		 if (operation == 2)
		{
			system("cls");
			add_cont(list, SIZE, String_Length);
		}
		else if (operation == 3)
		{
			system("cls");
			hideCursor(true);
			cout << "Input contact number:\n";
			cin >> index;
			cin.ignore();
			delete_cont(list, SIZE, String_Length, index);
		}
		else if (operation == 4)
		{
			system("cls");
			hideCursor(true);
			cout << "Input contact number:\n";
			cin >> index;
			cin.ignore();
			edit_cont(list, SIZE, String_Length, index);
		}
		else if (operation == 27)
		{
			exit(0);
		}
	}
}