#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col })
#define COLOR(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bg * 16 + fg)
using namespace std;

const short length = 40;

struct Contact
{
	char name[length]{ "Samir" };
	char surname[length]{ "Mammadli" };
	short age = 31;
	char place_of_birth[length]{ "Baku" };
};
void hideCursor(bool switch_cursor);
void addStudent(Contact **&list, int &size, const short length);
void print(Contact **list, int size, short &col, int index);
void menu(short &operation, short def_coord);
void delete_cont(Contact **&list, int &size);
void sorting(Contact **&list, int size);
void edit_cont(Contact **list, int size);
void search_cont(Contact **list, int size,const short length);



enum Colors
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	DARKGREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	DEFAULT = 7
};


void hideCursor(bool switch_cursor = false)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void menu(short &operation, short def_coord)
{
	int key = 0;
	while (key != 13)
	{
		COORDS(90, 0);
		cout << "*****Contact Book*****\n\n\n";
		COORDS(90, 2);
		cout << "Select an action:\n\n";
		COORDS(90, 3);
		if (operation == 1)
			COLOR(DARKGREEN, BLACK);
		cout << "1. Display All Contacts.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 4);
		if (operation == 2)
			COLOR(DARKGREEN, BLACK);
		cout << "2. Add new Contact.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 5);
		if (operation == 3)
			COLOR(DARKGREEN, BLACK);
		cout << "3. Delete Contact.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 6);
		if (operation == 4)
			COLOR(DARKGREEN, BLACK);
		cout << "4. Edit Contact.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 7);
		if (operation == 5)
			COLOR(DARKGREEN, BLACK);
		cout << "5. Sort Contacts.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 8);
		if (operation == 6)
			COLOR(DARKGREEN, BLACK);
		cout << "6. Search Contact.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(90, 9);
		if (operation == 7)
			COLOR(DARKGREEN, BLACK);
		cout << "7. Exit.\n";
		COLOR(DEFAULT, BLACK);
		COORDS(0, def_coord);

		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72 && operation > 1)
				operation--;
			else if (key == 80 && operation < 7)
				operation++;
		}
	}
}


void print(Contact **list, int size, short &col, int index = -1)
{
	COORDS(0, 2);
	if (size < 1 )
		cout << "There is no contacts!\n";
	else if (index > -1)
	{
		COORDS(0, 3);
		cout << "Name:   \t\tSurname:   \t\tAge:       Place of bitrh:\n";
		COORDS(0, col);
		printf("%d. %-21s", index + 1, list[index]->name);
		printf("%-24s", list[index]->surname);
		printf("%-11d", list[index]->age);
		printf("%s\n", list[index]->place_of_birth);
		col++;
	}
	else
	{
		cout << "Name:   \t\tSurname:   \t\tAge:       Place of bitrh:\n";
		for (int i = 0; i < size; i++)
		{
			COORDS(0, i + 4);
			printf("%d. %-21s",i+1, list[i]->name);
			printf("%-24s", list[i]->surname);
			printf("%-11d", list[i]->age);
			printf("%s\n", list[i]->place_of_birth);
			if (i > 7)
				col = i + 6;
		}
	}
	COORDS(0, col);
}





void addStudent(Contact **&list, int &size, const short length)
{
	hideCursor(true);
	system("cls");
	Contact **temp = new Contact*[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}
	temp[size] = new Contact;

	cout << "Insert new Contact's Name:\n";
	cin.getline(temp[size]->name, length);
	cout << "Insert new Contact's Surname:\n";
	cin.getline(temp[size]->surname, length);
	cout << "Insert new Contact's age:\n";
	cin >> temp[size]->age;
	cout << "Insert new Contact's Place of Birth:\n";
	cin.ignore();
	cin.getline(temp[size]->place_of_birth, length);
	list = temp;
	size++;
	system("pause");
	system("cls");
}

void delete_cont(Contact **&list, int &size)
{
	hideCursor(true);
	system("cls");
	int number;
	cout << "Enter contact number:\n";
	cin >> number;
	number--;
	if (number >= 0 && number < size)
	{
		size--;
		Contact **temp = new Contact*[size];
		for (int i = 0, j = 0; i < size+1; i++, j++)
		{
			i == number ? i++ : 0;
			i < size+1 ? temp[j] = list[i]: 0;
		}
		list = temp;
		cout << "Contact deleted!\n";
	}
	else
		cout << "Wrong Contact Number!\n";
	system("pause");
	system("cls");
}

void sorting(Contact **&list, int size)
{
	system("cls");
	int key = 0;
	int operation = 1;
	
	while (key != 13)
	{
		COORDS(0, 0);
		if (operation == 1)
			COLOR(DARKGREEN, BLACK);
		cout << "1. Sort by Name\n";
		COLOR(DEFAULT, BLACK);
		if (operation == 2)
			COLOR(DARKGREEN, BLACK);
		cout << "2. Sort by Surname\n";
		COLOR(DEFAULT, BLACK);
		if (operation == 3)
			COLOR(DARKGREEN, BLACK);
		cout << "3. Sort by Age\n";
		COLOR(DEFAULT, BLACK);
		if (operation == 4)
			COLOR(DARKGREEN, BLACK);
		cout << "4. Sort by Place of Birth\n";
		COLOR(DEFAULT, BLACK);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 72 && operation > 1)
				operation--;
			else if (key == 80 && operation < 4)
				operation++;
		}
	}

	if (operation == 1)
	{
		Contact *temp1 = new Contact;
		for (int i = 0; i < size-1; i++)
		{
			for (int j = i+1; j < size; j++)
			{
				if (strcmp(list[i]->name, list[j]->name) == 1)
				{
					temp1 = list[i];
					list[i] = list[j];
					list[j] = temp1;
				}
			}		
		}
	}
	else if (operation == 2)
	{
		Contact *temp1 = new Contact;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(list[i]->surname, list[j]->surname) == 1)
				{
					temp1 = list[i];
					list[i] = list[j];
					list[j] = temp1;
				}
			}
		}
	}
	else if (operation == 3)
	{
		Contact *temp1 = new Contact;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (list[i]->age > list[j]->age)
				{
					temp1 = list[i];
					list[i] = list[j];
					list[j] = temp1;
				}
			}
		}
	}
	else if (operation == 4)
	{
		Contact *temp1 = new Contact;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(list[i]->place_of_birth, list[j]->place_of_birth) == 1)
				{
					temp1 = list[i];
					list[i] = list[j];
					list[j] = temp1;
				}
			}
		}
	}
	system("cls");
}

void edit_cont(Contact **list, int size)
{
	hideCursor(true);
	system("cls");
	int number = 0;
	cout << "Enter Contact's number:\n";
	cin >> number;
	cin.ignore();
	number--;
	if (number >= 0 && number < size)
	{
		cout << number+1 << ". " << list[number]->name << "\t" << list[number]->surname << "\n\n";

		cout << "Edit Contact's Name:\n";
		cin.getline(list[number]->name, length);
		cout << "Edit Contact's Surname:\n";
		cin.getline(list[number]->surname, length);
		cout << "Edit Contact's age:\n";
		cin >> list[number]->age;
		cout << "Edit Contact's Place of Birth:\n";
		cin.ignore();
		cin.getline(list[number]->place_of_birth, length);
		cout << "Contact Edited!\n";
	}
	else
		cout << "Wrong Contact Number!\n";
	system("pause");
	system("cls");
}


void search_cont(Contact **list, int size, const short length)
{
	hideCursor(true);
	system("cls");
	short col = 5;
	bool found = false;
	char *temp = new char[length];
	cout << "Enter words to search:\n";
	cin.getline(temp, length);
	for (int i = 0; i < size; i++)
	{
		if (strstr(list[i]->name, temp) != 0  || strstr(list[i]->surname, temp) != 0)
		{
			print(list, size, col, i);
			found = true;
		}	
	}
	if (!found)
		cout << "No contacts found!\n";
	system("pause");
	system("cls");
}
