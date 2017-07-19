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


//void load(matrix **&, int, FILE*&);
//bool isempty(FILE *);
void hideCursor(bool);
void print_menu(char menu[][50] , short , short , int );
void load_matrix(matrix **&field, int, int, FILE* f);
void vipe_matrix(matrix **, int, int);
void write_matrix(matrix **field, int , int, FILE *f);
void control(matrix **&field, int &ax, int &bx, int row, int col, char &curr_symb, FILE* f);

//bool isempty(FILE * f)
//{
//	bool notempty;
//	fseek(f, 0, SEEK_END);
//	notempty = ftell(f);
//	fseek(f, 0, SEEK_SET);
//	return notempty;
//}


