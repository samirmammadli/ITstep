#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;


HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

#define COORDS(col, row) SetConsoleCursorPosition(H, {(short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(H, bg * 16 + fg)

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


struct matrix
{
	unsigned char symbol = ' ';
	short bg = DEFAULT;
	short fg = BLACK;
};