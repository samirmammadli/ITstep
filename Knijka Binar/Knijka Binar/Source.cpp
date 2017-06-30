#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Functions.h"
using namespace std;



void main()
{

	FILE* CL = fopen("cont.bin", "ab+");
	fseek(CL, 0, SEEK_END);
	int size = ftell(CL) / sizeof(Contact);
	fseek(CL, 0, SEEK_SET);
	Contact **list = new Contact*[size];

	for (int i = 0; i < size; i++)
	{
		list[i] = new Contact;
		fread(list[i], sizeof(Contact), 1, CL);
	}
	fclose(CL);

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


			CL = fopen("cont.bin", "wb");
			for (int i = 0; i < size; i++)
			{
				fwrite(list[i], sizeof(Contact), 1, CL);
			}
			fclose(CL);
			exit(0);
		}
	}
}