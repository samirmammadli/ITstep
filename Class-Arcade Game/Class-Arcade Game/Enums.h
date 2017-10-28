#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define COORDS(x, y) 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(x), short(y) });
using namespace std;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall, Hole };
const int field_width = 40;
const int field_height = 20;
class Character;


void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}




