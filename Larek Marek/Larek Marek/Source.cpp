#include <iostream>
#include <time.h>
using namespace std;

void print(int *arr, int size);
void init(int *arr, int size);

void main()
{
	srand(time(NULL));
	int size = 10;
	//int *arr = (int*)malloc(size * sizeof(int));  - sozdanie bez inicializacii.
	int *arr = (int*)calloc(size, sizeof(int)); // sozdanie s inicializaciey (0).
	init(arr, size);
	print(arr, size);
	arr = (int*)realloc(arr, ++size * sizeof(int));
	arr[size - 1] = 15;
	print(arr, size);
	free(arr);
}

void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void init(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}