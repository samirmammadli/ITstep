#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

// 0 - Empty
// 1 - Wall
// 2 - Food
// 3 - Player
void check_continue(int score);
int main()
{
	system("mode con cols=66 lines=27");
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
	cout << "\n\n\n\n\n";
	cout << "\t	`¶¶¶¶```¶¶``¶¶```¶¶¶¶```¶¶``¶¶``¶¶¶¶¶	" << endl;
	cout << "\t	¶¶``````¶¶¶`¶¶``¶¶``¶¶``¶¶`¶¶```¶¶	" << endl;
	cout << "\t	`¶¶¶¶```¶¶`¶¶¶``¶¶¶¶¶¶``¶¶¶¶````¶¶¶¶	" << endl;
	cout << "\t	````¶¶``¶¶``¶¶``¶¶``¶¶``¶¶`¶¶```¶¶	" << endl;
	cout << "\t	`¶¶¶¶```¶¶``¶¶``¶¶``¶¶``¶¶``¶¶``¶¶¶¶¶	" << endl;
	cout << "\n\n\t\t\tW - UP.\n";
	cout << "\t\t\tS - DOWN.\n";
	cout << "\t\t\tA - LEFT.\n";
	cout << "\t\t\tD - RIGHT.\n";
	cout << "\t\t\tSpace - Pause.\n\n\n\n";
	system("pause");
	//Initialization
	srand(time(0));
	const int rows = 25, cols = 65;
	int field[rows][cols];
	int tail[rows*cols][2];
	int count = 0;
	int check_moving = 0;
	int key = 0, key2 = 0;
	int foodX = rand() % (rows - 2) + 1, foodY = rand() % (cols - 2) + 1;
	int playerX = rows / 2, playerY = cols / 2;
	for (int i = 0; i < rows*cols; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tail[i][j] = -1;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
				field[i][j] = 1;
			else
				field[i][j] = 0;
		}
	}
	tail[0][0] = playerX, tail[0][1] = playerY;
	//Drawing
	while (true)
	{
		SetConsoleCursorPosition(h, { 0,0 });
		SetConsoleTextAttribute(h, 0);
		field[foodX][foodY] = 2;
		for (int k = 0; k < rows*cols; k++)
		{
			if (tail[k][0] > -1)
			{
				field[tail[k][0]][tail[k][1]] = 3;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (field[i][j] == 1)
				{
					SetConsoleTextAttribute(h, 23);
					cout << char(219);
				}
				else if (field[i][j] == 2)
				{
					SetConsoleTextAttribute(h, 10);
					cout << "*";
				}
				else if (field[i][j] == 3)
				{
					SetConsoleTextAttribute(h, 12);
					cout << 'o';
				}
				else
				{
					SetConsoleTextAttribute(h, 0);
					cout << ' ';
				}
				SetConsoleTextAttribute(h, 0);
			}
			cout << endl;
		}
		SetConsoleTextAttribute(h, 10);
		cout << "Score: " << count << "\t\t\t\t\t\t        " << endl;

		//Moves
		field[tail[0][0]][tail[0][1]] = 0;
		for (int i = 0; i <= count; i++)
		{
			tail[i][0] = tail[i + 1][0];
			tail[i][1] = tail[i + 1][1];
		}
		if (_kbhit())
		{
			key2 = _getch();
			if (key2 == 119 && check_moving != 2)
				key = key2;
			else if (key2 == 115 && check_moving != 1)
				key = key2;
			else if (key2 == 100 && check_moving != 4)
				key = key2;
			else if (key2 == 97 && check_moving != 3)
				key = key2;
			else if (key2 == 32)
			{
				system("pause");
				system("cls");
			}

		}
		if (key == 119) // W
		{
			playerX--;
			check_moving = 1;
		}

		else if (key == 115) // S
		{
			playerX++;
			check_moving = 2;
		}

		else if (key == 100) // D
		{
			playerY++;
			check_moving = 3;
		}

		else if (key == 97 && check_moving != 3) // A
		{
			playerY--;
			check_moving = 4;
		}
		//Touching
		if (field[playerX][playerY] == field[foodX][foodY])
		{
			foodX = rand() % (rows - 2) + 1, foodY = rand() % (cols - 2) + 1;
			count++;
		}
		tail[count][0] = playerX;
		tail[count][1] = playerY;
		if (field[playerX][playerY] == 1)
		{
			check_continue(count);
		}
		for (int j = 0; j < count; j++)
		{
			if (playerX == tail[j][0] && playerY == tail[j][1])
				check_continue(count);
		}
	}
}
void check_continue(int score)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int key = 0;
	system("cls");
	SetConsoleTextAttribute(h, 12);
	cout << "\n\n\n\n\n\n\n\tYOU LOOSE! \n";
	SetConsoleTextAttribute(h, 10);
	cout << "\tYour score: " << score << endl;
	SetConsoleTextAttribute(h, 12);
	cout << "\tPress ENTER to EXIT, or SPACE to try again!\n";
	SetConsoleTextAttribute(h, 0);
	while (key = _getch())
	{
		if (key == 13)
			exit(0);
		else if (key == 32)
			main();
	}
}