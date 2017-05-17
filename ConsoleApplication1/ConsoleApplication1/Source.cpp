#include <iostream>
#include <windows.h>
using namespace std;

void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	const int step = 15;
	int arr[step][step] = {};
	int size = step, count = 1, color = 1;
	for (int i = 0; i < step; i++)
	{
		size -= i;
		for (int j = i; j < size; j++)
		{
			for (int k = i; k < size; k++)
			{
				if (j == i)
				{
					arr[j][k] = count;
					count++;
				}
				else if (k == size - 1 && j < size - 1)
				{
					arr[j][k] = count;
					count++;
				}
				else if (j == size - 1)
				{
					arr[j][step - k - 1] = count;
					count++;
				}
			}
		}
		for (int j = i; j < size; j++)
		{
			for (int k = i; k < size; k++)
			{
				if (k == i  && j < size - 1 && j > i)
				{
					arr[step - j - 1][k] = count;
					count++;
				}
			}
		}
		size = step;
	}



	//Display on the screen
	for (int i = 0; i < step; i++)
	{
		for (int j = 0; j < step; j++)
		{
			if (arr[i][j] < 57)
				SetConsoleTextAttribute(h, color);
			else if (arr[i][j] < 105)
				SetConsoleTextAttribute(h, color + 1);
			else if (arr[i][j] < 145)
				SetConsoleTextAttribute(h, color + 2);
			else if (arr[i][j] < 177)
				SetConsoleTextAttribute(h, color + 3);
			else if (arr[i][j] < 201)
				SetConsoleTextAttribute(h, color + 4);
			else if (arr[i][j] < 217)
				SetConsoleTextAttribute(h, color + 5);
			else if (arr[i][j] < 225)
				SetConsoleTextAttribute(h, color + 6);
			else
			{
				SetConsoleTextAttribute(h, color + 7);
			}
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(h, color + 7);

	/*for (int i = 0; i < 220; i++)
	{
		SetConsoleTextAttribute(h, i);
		cout << i << "\t";
	}*/
}