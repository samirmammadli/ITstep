#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <Windows.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define COORDS(col, row) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + fg)
#define findclose _findclose
using namespace std;

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

struct FileProp
{
	string type;
	string attr = "";
	string size_type = "Bytes";
	string time_c;
	string time_w;
	string time_a;
	double size;
};

struct FileInfoCopy
{
	string buffer;
	_finddata_t file;
};

class Printing {

	enum figPos {
		VERTICAL, HORIZONTAL, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT
	};
	  char* symbols;
	
public:
	Printing()
	{
		symbols = new  char[6];
		symbols[VERTICAL] = 186;
		symbols[HORIZONTAL] = 205;
		symbols[UPLEFT] = 201;
		symbols[UPRIGHT] = 187;
		symbols[DOWNLEFT] = 200;
		symbols[DOWNRIGHT] = 188;
	}
	void  printTable(int width = 0, int height = 0, int indentW = 0, int indentH = 0)
	{
		setlocale(LC_ALL, "C");
		for (int i = indentH; i < height + indentH; i++)
		{
			for (int j = indentW; j < width + indentW; j++)
			{
				if (i == indentH && j == indentW)
				{
					COORDS(i, j);
						cout << symbols[UPLEFT];
				}
				else if (i == indentH && j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[UPRIGHT];
				}
				else if (i == indentH + height - 1 && j == indentW)
				{
					COORDS(i, j);
						cout << symbols[DOWNLEFT];
				}
				else if (i == indentH + height - 1 && j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[DOWNRIGHT];
				}
				else if (j == indentW)
				{
					COORDS(i, j);
						cout << symbols[VERTICAL];
				}
				else if (j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[VERTICAL];
				}
				else if (i == indentH)
				{
					COORDS(i, j);
						cout << symbols[HORIZONTAL];
				}
				else if (i == indentH + height - 1)
				{
					COORDS(i, j);
						cout << symbols[HORIZONTAL];
				}
			}
		}
		setlocale(LC_ALL, "Rus");
	}
	void printText(int indentH, int indentW, Colors bg, Colors fg, string text)
	{
		COORDS(indentH, indentW);
		COLORS(fg, bg);
		cout << text;
		COLORS(CYAN, DARKBLUE);
	}
};

void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
