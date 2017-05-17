#include <iostream>
#include <conio.h>
using namespace std;


int search_number(int arr[], int size, int x)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] == x)
		{
			cout << endl;
			return 1;
		}
			
	}
	cout << endl;
	return 0;
}

int mass_sum(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
void digit_to_space()
{
	char key;
	while (true)
	{
		key = _getch();
		if (key > 47 && key < 58)
		{
			key = 32;
		}
		else if (key == 13)
		{
			cout << endl;
		}
		_putch(key);
	}
}
void lower_to_upper()
{
	char key;
	while (true)
	{
		key = _getch();
		if (key > 64 && key < 91)
		{
			key += 32;
		}
		else if (key > 96 && key < 123)
		{
			key -= 32;
		}
		else if (key == 13)
		{
			cout << endl;
		}
		_putch(key);
	}
}
void char_filter()
{
	char key;
	while (true)
	{
		key = _getch();
		if (key > 47 && key < 58 )
		{
			0;
		}
		else if (key == 13)
		{
			cout << endl;
		}
		else
			_putch(key);
	}
}
void morze()
{
	char arr[36][4];
}