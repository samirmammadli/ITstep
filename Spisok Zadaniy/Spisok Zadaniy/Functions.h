#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
#define COORDS(row, col) SetConsoleCursorPosition(H, { (short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(H, {bg *16 + fg} )




bool check_empty(FILE* f);


void menu(char **list, short def_col);
void save(char **str, int w, const char *patch);
void init(char **&str, int &w, int h);
void add_task(char **&str, int &w, int h);
void hideCursor(bool switch_cursor);
void delete_task(char **&str, int &w, int h, int &pos);
void sort_tasks(char **str, int w, int h, bool side, int &pos);


FILE * f;

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


bool check_empty(FILE* f)
{
	COORDS(15, 18);
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);
	return size;
}


void hideCursor(bool switch_cursor = false)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}


void menu(char **list, short def_col)
{
	COLORS(MAGENTA, BLACK);
	for (short i = 1; i < 12; i++)
	{
		COORDS(67, i);
		cout << "**";
		COORDS(116, i);
		cout << "**";
	}
	for (short i = 67; i < 118; i++)
	{
		COORDS(i, 2);
		cout << "*";
		COORDS(i, 12);
		cout << "*";
		COORDS(i, 11);
		cout << "*";
	}
	COLORS(DEFAULT, BLACK);

	COORDS(69, 1);
	COLORS(MAGENTA, BLACK);
	cout << "***************  Tasks List  *******************";
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

	
}

void save(char **str, int w, const char *patch)
{
	f = fopen(patch, "w");
	for (int i = 0; i < w; i++)
	{

		fputs(str[i], f);
		i < w - 1 ? fputc('\n', f) : fputc('\0', f);
	}
	fclose(f);
}

void init(char **&str, int &w, int h)
{
	char ** temp = new char*[w + 1];
	temp[w] = new char[h];
	for (int i = 0; i < w; i++)
	{
		temp[i] = str[i];
	}
	w++;
	str = temp;
}

void add_task(char **&str, int &w, int h)
{
	hideCursor(true);
	char ** temp = new char*[w + 1];
	for (int i = 0; i < w; i++)
	{
		temp[i] = str[i];
	}
	temp[w] = new char[h];
	system("cls");
	cout << "Add new task:\n";
	cin.getline(temp[w], h);
	cout << "\n[+]Task Added!\n";
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
			i == pos && pos != w - 1 ? i++ : 0;
			list[j] = str[i];
		}
		if (pos == w - 1)
			pos--;
		w--;
		str = list;
		system("cls");
	}

}

void sort_tasks(char **str, int w, int h, bool side, int &pos)
{
	char *temp = new char[h];
	if (side == 1 && pos < w - 1)
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