#include "Functions.h"
#include <iostream>
#include <time.h>
#include <conio.h>



void main()
{
	srand(time(NULL));
	int oper = 0;
	cout << "Vvedite nomer zadaniya: ";
	cin >> oper;
	if (oper == 1)
	{
		const int size = 10;
		int value, arr[size];
		bool check_value_exist;
		cout << "Vvedite chislo: ";
		cin >> value;
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 + 1;
		}
		check_value_exist = search_number(arr, size, value);
		if (check_value_exist)
			cout << "True!\n";
		else
			cout << "False!\n";
	}
	else if (oper == 2)
	{
		const int size = 10;
		int arr[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 150;
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "Summa elementov : " << mass_sum(arr, size) << endl;
	}
	else if (oper == 3)
	{
		cout << "Vvedite simvoli/cifri: ";
		digit_to_space();

	}
	else if (oper == 4)
	{
		cout << "Vvedite simvoli/cifri: ";
		char_filter();
	}
	else if(oper == 5)
	{
		cout << "Vvedite simvoli/cifri: ";
		lower_to_upper();
	}
}