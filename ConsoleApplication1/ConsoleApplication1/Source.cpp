#include <iostream>
using namespace std;

void main()
{
	const int size = 15;
	int arr[size][size] = {};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}