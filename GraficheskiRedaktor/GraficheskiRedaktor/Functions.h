#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

#define COORDS(col, row) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + fg)

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
	short bg = WHITE;
	short fg = BLACK;
};




void print_menu(char menu[][50] , short , short , int );
void vipe_matrix(matrix **, int);