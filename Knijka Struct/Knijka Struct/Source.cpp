#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;



void main()
{
	
	int size = 4;
	Contact **list = new Contact*[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = new Contact;
	}
	strcpy(list[1]->name, "Rufat");
	strcpy(list[1]->surname, "Gulabli");
	list[1]->age = 27;
	strcpy(list[1]->place_of_birth, "Agdash");

	strcpy(list[2]->name, "Kamal");
	strcpy(list[2]->surname, "Jafarov");
	list[2]->age = 33;
	strcpy(list[2]->place_of_birth, "Kiev");

	strcpy(list[3]->name, "Vugar");
	strcpy(list[3]->surname, "Yusubov");
	list[3]->age = 69;
	strcpy(list[3]->place_of_birth, "Bangladesh");
	short operation = 1;
	short def_col = 13;
	while (true)
	{
		hideCursor();
		menu(operation, def_col);
		if (operation == 1)
		{
			print(list, size, def_col);
		}
		else if (operation == 2)
		{
			addStudent(list, size, length);
		}
		else if (operation == 3)
		{
			delete_cont(list, size);
			cin.ignore();
		}
		else if (operation == 4)
		{
			edit_cont(list, size);
		}
		else if (operation == 5)
		{
			sorting(list, size);
			print(list, size, def_col);
		}
		else if (operation == 6)
		{
			search_cont(list, size, length);
		}
		else if (operation == 7)
		{
			exit(0);
		}
	}
}