#include <iostream>
#include <conio.h>
using namespace std;

int str_length(char *arr);
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
}

//Funcitons

int str_length(char *arr)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0' ; i++)
	{
		count++;
	}
	return count;
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
	int size = str_length(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - 1 - i])
			palendrom = false;
	}
}