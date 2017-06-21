#include <iostream>
#include <conio.h>
#include "Functions.h"
using namespace std;



void main()
{
	char *pP;
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
		char arr2[size] = {"World"};
		char arr3[size] = { "Big World is Great!" };
		char index;
		cout << "Stroka1 - " << arr1 << "\nStroka2 - " << arr2 << endl;
		cout << "Vvedite index podzadaniya(a,b,c,d,e,f,g): ";
		cin >> index;
		switch (index)
		{
		case 'a':
			cout << "Dlina stroki 1: " << mystrlen(arr1) << "\nDlina stroki 2: " << mystrlen(arr2) << endl;
			break;
		case 'b':
			cout << mystrcpy(arr1, arr2) << endl;
 			break;
		case 'c':
			cout << mystrcat(arr1, arr2) << endl;
			break;
		case 'd':
			char s;
			cout << "Vvedite simvol, kotoriy jelaete nayte v stroke 1: ";
			cin >> s;
			cout << mystrchr(arr1, s) << endl;
			break;
		case 'e':
			pP = mystrstr(arr3, "is gr");
			if (pP != 0)
				cout << pP << endl;
			break;
		case 'f':
			cout << "Stroki ravni:\t\t" << mystrcmp("Hello", "Hello") << endl;
			cout << "Pervaya stroka bolwe:\t" << mystrcmp("Hello World", "Hello") << endl;
			cout << "Vtoraya stroka bolwe:\t" << mystrcmp("Hello", "Hello World") << endl;
			break;
		case 'g':
			cout << StringToNumber("123456") << endl;
			break;
		case 'h':
			pP = NumberToString(12345);
			cout << pP << endl;
			break;
		case 'i':
			cout << Uppercase(arr3) << endl;
			break;
		case 'j':
			cout << Lowercase(arr3) << endl;
			break;
		default:
			break;
		}
	}
}
