#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;



void main()
{
	int size = 1;
	Contact **list = new Contact*[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = new Contact;
	}

	short operation = 1;
	short def_col = 13;
	while (true)
	{
		
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
		
		}
		else if (operation == 7)
		{
			exit(0);
		}
	}
}