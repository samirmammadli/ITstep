#include <iostream>
using namespace std;

void main()
{
	const int step = 15;
	int arr[step][step] = {};
	int size = step, count = 1;
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
			}
		}
	}



	//Display on the screen
	for (int i = 0; i < step; i++)
	{
		for (int j = 0; j < step; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}