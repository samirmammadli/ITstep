#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg *16 + fg )


void add_task(char **&str, int &w, int h);
void hideCursor(bool switch_cursor);
void delete_task(char **&str, int &w, int h, int &pos);
void sort_tasks(char **str, int w, int h, bool side, int &pos);






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


void add_task(char **&str, int &w, int h)
{
	hideCursor(true);
	char ** temp = new char*[w+1];
	for (int i = 0; i < w; i++)
	{
		temp[i] = new char[h];
		strcpy(temp[i], str[i]);
	}
	temp[w] = new char[h];
	system("cls");
	cout << "Add new task:\n";
	cin.getline(temp[w], h);
	cout << "\n[+]Task Added!\n";
	for (int i = 0; i < w; i++)
	{
		delete[]str[i];
	}
	w++;
	str = temp;
	system("pause");
	system("cls");
	hideCursor();
}

void delete_task(char **&str, int &w, int h, int &pos)
{
	if (w > 0)
	{
		char **list = new char*[w - 1];
		for (int i = 0, j = 0; j < w - 1; i++, j++)
		{
			list[j] = new char[h];
			i == pos && pos != w - 1 ? i++ : 0;
			strcpy(list[j], str[i]);
		}
		if (pos == w - 1)
			pos--;
		for (int i = 0; i < w; i++)
		{
			delete[]str[i];
		}

		w--;
		str = list;
		system("cls");
	}
	
}

void sort_tasks(char **str, int w, int h, bool side, int &pos)
{
	char *temp = new char[h];
	if (side == 1 && pos < w-1)
	{
		strcpy(temp, str[pos]);
		strcpy(str[pos], str[pos + 1]);
		strcpy(str[pos + 1], temp);
		pos++;
	}
	else if (side == 0 && pos > 0)
	{
		strcpy(temp, str[pos]);
		strcpy(str[pos], str[pos - 1]);
		strcpy(str[pos - 1], temp);
		pos--;
	}
	system("cls");
}



