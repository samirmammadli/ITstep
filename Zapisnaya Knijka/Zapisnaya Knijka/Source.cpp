#include <iostream>
#include <Windows.h>
#include "Functions.h"
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
#define String_Length 100
using namespace std;


void main()
{
	short def_col = 13;
	hideCursor();
	int SIZE = 4;
	short index = 0;
	int operation;
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
		COORDS(60, 0);
		cout << "*****Contact Book.*****\n\n\n";
		COORDS(60, 2);
		cout << "Select an action:\n\n";
		COORDS(60, 3);
		cout << "1. Display All Contacts.\n";
		COORDS(60, 4);
		cout << "2. Add new Contact.\n";
		COORDS(60, 5);
		cout << "3. Delete Contact.\n";
		COORDS(60, 6);
		cout << "4. Edit Contact.\n";
		COORDS(60, 7);
		cout << "5. Sort Contacts by Name.\n";
		COORDS(60, 8);
		cout << "6. Search Contact.\n";
		COORDS(60, 9);
		cout << "7. Exit.\n";
		COORDS(0, def_col);

		cin >> operation;
		cin.ignore();

		if (operation == 1)
		{
			disp_list(list, SIZE, def_col);
		}
		else if (operation == 2)
		{
			system("cls");
			add_cont(list, SIZE, String_Length);
		}
		else if (operation == 3)
		{
			system("cls");
			cout << "Input contact number:\n";
			cin >> index;
			delete_cont(list, SIZE, String_Length, index);
		}
		else if (operation == 4)
		{
			system("cls");
			cout << "Input contact number:\n";
			cin >> index;
			cin.ignore();
			edit_cont(list, SIZE, String_Length, index);
		}
		else if (operation == 5)
		{
			sort_cont(list, SIZE, String_Length);
			disp_list(list, SIZE, def_col);
		}
		else if (operation == 7)
		{
			exit(0);
		}
		else if (operation == 6)
		{
			search_cont(list, SIZE, String_Length);
		}
	}
}