#include <iostream>
using namespace std;




void main()
{
	const int size = 5;
	int horseX = 0, horseY = 0;
	int arr[size][size] = {};

	arr[horseX][horseY] = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << "\n\n";
	}
}
