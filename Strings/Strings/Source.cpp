#include <iostream>
#include <conio.h>
using namespace std;

void change_space(char *arr);
void print(char *arr);
void init(char *arr, int size);

void main()
{
	int oper = 0;
	cout << "Vvedite nomer zadaniya: ";
	cin >> oper;
	if (oper == 1)
	{
		char arr[1000] = {};
		cout << "Vvedite stroku:\n";
		gets_s(arr);
		//init(arr, 1000);
		change_space(arr);
		print(arr);
	}

}

void change_space(char *arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == 32)
		{
			arr[i] = '\t';
		}
	}
}

void print(char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		cout << arr[i];
		i++;
	}
	cout << endl;
}

void init(char *arr, int size)
{
	int key = 0;
	for (int i = 0; i < size && key != 13; i++)
	{
		key = getch();

		arr[i] = key;
		cout << arr[i];

	}
	cout << endl;
}