#include <iostream>
#include <conio.h>
#include "Functions.h"
using namespace std;

void change_space(char *arr);
void print(char *arr);
void find_num(char *arr, int &letter, int &number, int &other);
void words_count(char *arr, int &words);
void is_palendrom(char *arr, bool &palendrom);

void main()
{
	const int size = 100;
	int oper = 0;
	cout << "Vvedite nomer zadaniya: ";
	cin >> oper;
	if (oper == 1)
	{
		char arr[size] = {};
		cout << "Vvedite stroku:\n";
		getchar();
		cin.getline(arr, size);
		change_space(arr);
		print(arr);
	}
	else if (oper == 2)
	{
		int number = 0, letter = 0, other = 0;
		char arr[size] = {};
		cout << "Vvedite stroku:\n";
		getchar();
		cin.getline(arr, size);
		find_num(arr, letter, number, other);
		cout << "\nBukv:\t" << letter << endl;
		cout << "Chisel:\t" << number << endl;
		cout << "Drugoe:\t" << other << endl;
	}
	else if (oper == 3)
	{
		int words = 0;
		char arr[size] = {};
		cout << "Vvedite stroku:\n";
		getchar();
		cin.getline(arr, size);
		words_count(arr, words);
		cout <<"Vsego slov: " << words << endl;
	}
	else if (oper == 6)
	{
		bool palendrom = true;
		char arr[size] = {};
		cout << "Vvedite stroku:\n";
		getchar();
		cin.getline(arr, size);
		is_palendrom(arr, palendrom);
		if (palendrom)
			cout << "Stroka yavlaetsa palendromom!\n";
		else
			cout << "Stroka ne yavlaetsa palendromom!\n";
	}
	else if (oper == 7)
	{
		char arr1[size] = {"Hello"};
		char arr2[size] = {"World!"};
		char index;
		cout << "Stroka1 - " << arr1 << "\nStroka2 - " << arr2 << endl;
		cout << "Vvedite index podzadaniya: ";
		cin >> index;
		switch (index)
		{
		case 'a':
			cout << "Dlina stroki 1: " << mystrlen(arr1) << "\nDlina stroki 2: " << mystrlen(arr2) << endl;
			break;
		case 'b':
			
			break;
		case 'c':
			cout << mystrcat(arr1, arr2) << endl;
			break;
		default:
			break;
		}
	}
}

//Funcitons
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

void find_num(char *arr, int &letter, int &number, int &other)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 48 && arr[i] <= 57)
			number++;
		else if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
			letter++;
		else
			other++;
	}
}

void words_count(char *arr, int &words) // 1 bukvu za slovo ne schitaet
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		while (arr[i] == 45 || (arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
		{
			count++;
			i++;
		}
		count > 1 ? words++ : 0;
		count = 0;
	}
}

void is_palendrom(char *arr, bool &palendrom)
{
	int size = mystrlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - 1 - i])
			palendrom = false;
	}
}