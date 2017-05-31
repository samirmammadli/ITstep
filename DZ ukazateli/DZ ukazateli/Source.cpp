#include <iostream>
#include <time.h>
using namespace std;

void mult_sum(int *arr, int size, int &sum, int &mult);
void find_pos(int *arr, int size, int &pos, int &neg, int &nul);
void find_average(int *arr, int size, int &average, int &even, int &odd);
int* alloc(int size);
void init(int *arr, int size);
void print(int *arr, int size);
void delete_arr(int *arr);
int* insert_end(int *arr, int &size, int value);
int* insert_arr(int *arr, int &size, int value, int index);
int* delete_index(int *arr, int &size, int value);

void main()
{
	srand(time(NULL));
	int oper = 0;
	cout << "Vvedite nomer zadaniya: ";
	cin >> oper;
	if (oper == 1)
	{
		const int size = 10;
		int arr[size], sum = 0, mult = 1;
		cout << "Elementi massiva: ";
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 11;
			cout << arr[i] << ',';
		}
		mult_sum(arr, size, sum, mult);
		cout << "\n\nSumma vsex elementov: " << sum << "\nProizvedenie vsex elementov: " << mult << endl;
	}
	else if (oper == 2)
	{
		const int size = 10;
		int arr[size], neg = 0, pos = 0, nul = 0;
		cout << "Elementi massiva: ";
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 21 - 10;
			cout << arr[i] << ',';
		}
		find_pos(arr, size, pos, neg, nul);
		cout << "\n\nPolojitelnix elementov: " << pos << "\nOtricatelnix elementov: " << neg << endl;
		cout << "Ravnix 0-lu: " << nul << endl;
	}
	else if (oper == 3)
	{
		const int size = 10;
		int arr[size], average = 0, even = 0, odd = 0;
		cout << "Elementi massiva: ";
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 101;
			cout << arr[i] << ',';
		}
		find_average(arr, size, average, even, odd);
		cout << "\n\nSrednee arifmeticheskoe: " << average << "\nChetnix: " << even << endl;
		cout << "Nechetnix: " << odd << endl;
	}
	else if (oper == 4)
	{
		int size = 0, *arr, value = 0;
		cout << "Vvedite razmer massiva: ";
		cin >> size;
		arr = alloc(size);
		init(arr, size);
		print(arr, size);
		cout << "Vvedite dopolnitelniy element: ";
		cin >> value;
		arr = insert_end(arr, size, value);
		print(arr, size);
	}
	else if (oper == 5)
	{
		int size = 0, *arr, value = 0, index = 0;
		cout << "Vvedite razmer massiva: ";
		cin >> size;
		arr = alloc(size);
		init(arr, size);
		print(arr, size);
		cout << "Vvedite index vstavki, zatem znachenie:\n";
		cin >> index >> value;
		if (index < size && index >= 0)
		{
			arr = insert_arr(arr, size, value, index);
			print(arr, size);
		}
		else
			cout << "Vi vveli nekkorektniy index!\n";
	}
	else if (oper == 6)
	{
		int size = 0, *arr, index = 0;
		cout << "Vvedite razmer massiva: ";
		cin >> size;
		arr = alloc(size);
		init(arr, size);
		print(arr, size);
		cout << "Vvedite index kotoriy jelaete udalit: ";
		cin >> index;
		if (index < size && index >= 0)
		{
			arr = delete_index(arr, size, index);
			print(arr, size);
		}
		else
			cout << "Vi vveli nekkorektniy index!\n";
	}
}

void mult_sum(int *arr, int size, int &sum, int &mult)
{
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		mult *= arr[i];
	}
}

void find_pos(int *arr, int size, int &pos, int &neg, int &nul)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] > 0 ? pos++ : (arr[i] < 0 ? neg++ : nul++);
	}
}

void find_average(int *arr, int size, int &average, int &even, int &odd)
{
	for (int i = 0; i < size; i++)
	{
		average += arr[i];
		arr[i] % 2 == 0 ? even++ : odd++;
	}
	average /= size;
}

int* alloc(int size)
{
	int *arr = new int[size] {};
	return arr;
}

void init(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000;
	}
}

void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void delete_arr(int *arr)
{
	delete[]arr;
}

int* insert_end(int *arr, int &size, int value)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	size++;
	delete_arr(arr);
	arr = temp;
	return arr;
}

int* insert_arr(int *arr, int &size, int value, int index)
{
	int *temp = new int[size + 1];
	int n = 0;
	for (int i = 0; i < size; i++, n++)
	{
		if (n == index)
		{
			temp[n] = value;
			i--;
		}
		else
		{
			temp[n] = arr[i];
		}
	}
	size++;
	delete_arr(arr);
	arr = temp;
	return arr;
}

int* delete_index(int *arr, int &size, int index)
{
	size--;
	int *temp = new int[size];
	int n = 0;
	for (int i = 0; i < size; i++, n++)
	{
		if (i == index)
		{
			n++;
			temp[i] = arr[n];
		}
		else
		{
			temp[i] = arr[n];
		}
	}
	delete_arr(arr);
	arr = temp;
	return arr;
}