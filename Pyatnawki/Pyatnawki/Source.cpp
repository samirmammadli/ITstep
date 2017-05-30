#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	int timer = time(0);
	const int size = 4;
	int arr[size][size];
	int key, zeroX = 0, zeroY = 0;
	int difficulty, rand1, rand2, rand3, rand4, buffer, count  = 0;
	cout << "Select difficulty: ";
	cin >> difficulty;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = count;
			count++;
		}
	}
		//Change random position
	for (int i = 0; i < difficulty; i++)
	{
		rand1 = rand() % size;
		rand2 = rand() % size;
		rand3 = rand() % size;
		rand4 = rand() % size;


		buffer = arr[rand1][rand2];
		arr[rand1][rand2] = arr[rand3][rand4];
		arr[rand3][rand4] = buffer;
		if (arr[rand1][rand2] == 0)
		{
			zeroX = rand1, zeroY = rand2;
		}
		else if (arr[rand3][rand4] == 0)
		{
			zeroX = rand3, zeroY = rand4;
		}
	}
	while (true)
	{
		//Draw
		SetConsoleCursorPosition(h, { 0,0 });
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t" << "Timer: " <<time(0) - timer << "\n\n";
		for (int i = 0; i < size; i++)
		{
			cout << "\t\t\t";
			for (int j = 0; j < size; j++)
			{
				if (arr[i][j] == 0)
				{
					SetConsoleTextAttribute(h, 12);
				}
				cout << arr[i][j] << "\t";
				SetConsoleTextAttribute(h, 7);
				
			}
			cout << "\n\n";
		}
		     // Moves
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				//Left
				if (key == 75 && zeroY > 0)
				{
					arr[zeroX][zeroY] = arr[zeroX][zeroY - 1];
					zeroY--;
					arr[zeroX][zeroY] = 0;
				}
				//Right
				else if (key == 77 && zeroY < size - 1)
				{
					arr[zeroX][zeroY] = arr[zeroX][zeroY + 1];
					zeroY++;
					arr[zeroX][zeroY] = 0;
				}
				//Up
				else if (key == 72 && zeroX > 0)
				{
					arr[zeroX][zeroY] = arr[zeroX - 1][zeroY];
					zeroX--;
					arr[zeroX][zeroY] = 0;
				}
				//Down
				else if (key == 80 && zeroX < size - 1)
				{
					arr[zeroX][zeroY] = arr[zeroX + 1][zeroY];
					zeroX++;
					arr[zeroX][zeroY] = 0;
				}
			}
		}
	}
}