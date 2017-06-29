#include <iostream>
#include <Windows.h>
#include "Functions.h"
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
using namespace std;

const short length = 100;

struct Contact
{
	char name[length]{"Samir"};
	char surname[length]{"Mammadli"};
	short age = 0;
	char place_of_birth[length]{"Baku"};
};


void main()
{
	int size = 2;
	Contact **list = new Contact*[size];
	list[0] = new Contact;
	list[1] = list[0];

	int operation = 0;
	short def_col = 13;
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
		}
		else if (operation == 2)
		{
			cout << list[0]->age << endl << list[0]->name << endl << list[0]->surname << endl << list[0]->place_of_birth << endl;
			cout << list[1]->age << endl << list[1]->name << endl << list[1]->surname << endl << list[1]->place_of_birth << endl;
		}
		else if (operation == 3)
		{
			
		}
		else if (operation == 4)
		{
		
		}
		else if (operation == 5)
		{
		
		}
		else if (operation == 6)
		{
		
		}
		else if (operation == 7)
		{
	
		}
	}
}