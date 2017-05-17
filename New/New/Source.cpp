#include <iostream>
#include <Windows.h>
using namespace std;

void init(int arr[], int lenght);
void print(int arr[], int lenght);

void main()
{
	int arr[10] = {};
	init(arr, 10);
	print(arr, 10);
}

void init (int arr[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		arr[i] = rand() % lenght;
	}
}

void print (int arr[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}