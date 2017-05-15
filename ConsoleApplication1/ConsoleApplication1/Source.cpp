#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	const int step = 15;
	int arr[step][step] = {};
	int size = step, count = 1;
	for (int i = 0; i < step; i++)
	{
		size -= i;
		for (int j = i; j < size; j++)
		{
			for (int k = i; k < size; k++)
			{h
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
				if (k == i  && j < size -1 && j > i)
				{
					arr[step -j - 1][k] = count;
					count++;
				}
			}
		}
		size = step;
	}



	//Display on the screen
	for (int i = 0; i < step; i++)
	{
		SetConsoleTextAttribute(h, i + 1);
		for (int j = 0; j < step; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	/*for (int i = 0; i < 220; i++)
	{
		SetConsoleTextAttribute(h, i);
		cout << i << "\t";
	}*/
}