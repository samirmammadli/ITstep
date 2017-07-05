#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg *16 + fg )

void disp_list(char **str, int w, short &col, int &pos);
void add_cont(char **&str, int &w, int h);
void sort_cont(char **str, int w, int h);
void delete_cont(char **&str, int &w, int h, int contact_number);
void edit_cont(char **str, int w, int h, int contact_number);
void hideCursor(bool switch_cursor);




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

void disp_list(char **str, int w, short &col, int &pos)
{
	COORDS(0, 2);
	if (w == 1 && str[0][0] == '\0')
	{
		COLORS(CYAN, BLACK);
		cout << "There is no tasks!\n";
		COLORS(DEFAULT, BLACK);
	}
	else
	{
		COLORS(CYAN, BLACK);
		cout << "Tasks:\n";
		for (int i = 0; i < w; i++)
		{
			COORDS(0, i + 4);
			COLORS(CYAN, BLACK);
			cout << i + 1;
			COLORS(DEFAULT, BLACK);
			cout << ". " << str[i] << "\t" << endl;
			if (i > 7)
				col = i + 6;
		}
	}
	COORDS(0, col);
}

void add_cont(char **&str, int &w, int h)
{
	hideCursor(true);
	if (w == 1 && str[0][0] == '\0')
	{
		cout << "Please, input Name of new contact:\n";
		cin.getline(str[0], h);
	}
	else
	{
		char **temp = new char*[w + 1];
		for (int i = 0; i < w + 1; i++)
		{
			temp[i] = new char[h];
		}
		for (int i = 0; i < w; i++)
		{
			strcpy(temp[i], str[i]);
		}
		cout << "Please, input Name of new contact:\n";
		cin.getline(temp[w], h);
		for (int i = 0; i < w; i++)
		{
			delete[]str[i];
		}
		delete[]str;
		str = temp;
		w++;
	}
	cout << "[+] New Contact Added!\n";
	hideCursor();
	system("pause");
	system("cls");
}

void sort_cont(char **str, int w, int h)
{
	short biggest_string = 0;
	char *temp = new char[h];
	for (int i = 0; i < w; i++)
	{
		for (int j = i + 1; j < w; j++)
		{
			biggest_string = strcmp(str[i], str[j]);
			if (biggest_string == 1)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
	delete[]temp;
	system("cls");
}

void delete_cont(char **&str, int &w, int h, int contact_number)
{
	if (contact_number < 1 || contact_number > w)
		cout << "[-] Incorrect contact number inputed!\n";
	else if (w == 1)
	{
		str[0][0] = '\0';
		cout << "All Contacts are Deleted!\n";
	}
	else
	{
		contact_number--;
		char **temp_str = new char*[w - 1];
		for (int i = 0; i < w - 1; i++)
		{
			temp_str[i] = new char[h];
		}
		for (int i = 0, j = 0; j < w - 1; i++, j++)
		{
			i == contact_number && contact_number != w - 1 ? i++ : 0;
			strcpy(temp_str[j], str[i]);
		}
		for (int i = 0; i < w; i++)
		{
			delete[]str[i];
		}
		delete[]str;
		str = temp_str;
		w--;
		cout << "[+] Contact Deleted!\n";
	}
	hideCursor();
	system("pause");
	system("cls");
}

void edit_cont(char **str, int w, int h, int contact_number)
{
	if (w == 1 && str[0][0] == '\0')
		cout << "No contacts to edit!\n";
	else
	{
		cout << contact_number << ". " << str[contact_number - 1] << endl;
		cout << "Edit contact to: \n";
		cin.getline(str[contact_number - 1], h);
		cout << "[+] Contact changed!\n";
	}
	hideCursor();
	system("pause");
	system("cls");
}



