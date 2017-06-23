#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
using namespace std;


void disp_list(char **str, int w, short &col)
{
	COORDS(0, 2);
	if (w == 1 && str[0][0] == '\0')
		cout << "There is no contacts!\n";
	else
	{
		cout << "Contacts:\n";
		for (int i = 0; i < w; i++)
		{
			COORDS(0, i + 4);
			cout << i + 1 << ". " << str[i] << "\t" << endl;
			if (i > 7)
				col = i + 6;
		}
	}
	COORDS(0, col);
}

void add_cont(char **&str, int &w, int h)
{
	if (w == 1 && str[0][0] == '\0')
	{
		cout << "Please, input Name of new contact:\n";
		cin.getline(str[0], h);
	}
	else
	{
		char **temp = new char*[w + 1];
		for (int i = 0; i < w + 1; i++)
		{
			temp[i] = new char[h];
		}
		for (int i = 0; i < w; i++)
		{
			strcpy(temp[i], str[i]);
		}
		cout << "Please, input Name of new contact:\n";
		cin.getline(temp[w], h);
		for (int i = 0; i < w; i++)
		{
			delete[]str[i];
		}
		delete[]str;
		str = temp;
		w++;
	}
	cout << "[+] New Contact Added!\n";
	system("pause");
	system("cls");
}

void sort_cont(char **str, int w, int h)
{
	short biggest_string = 0;
	char *temp = new char[h];
	for (int i = 0; i < w; i++)
	{
		for (int j = i+1; j < w; j++)
		{
			biggest_string = strcmp(str[i], str[j]);
			if (biggest_string == 1)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
	delete[]temp;
	system("cls");
}

void delete_cont(char **&str, int &w, int h, int contact_number)
{
	if (contact_number < 1 || contact_number > w)
		cout << "[-] Incorrect contact number inputed!\n";
	else if (w == 1)
	{
		str[0][0] = '\0';
		cout << "All Contacts are Deleted!\n";
	}
	else
	{
		char **temp_str = new char*[w - 1];
		for (int i = 0; i < w - 1; i++)
		{
			temp_str[i] = new char[h];
		}
		for (int i = 0, j = 0; i < w ; i++, j++)
		{
			i == contact_number - 1 ? i++ : 0;
			strcpy(temp_str[j], str[i]);
		}
		for (int i = 0; i < w; i++)
		{
			delete[]str[i];
		}
		delete[]str;
		str = temp_str;
		w--;
		cout << "[+] Contact Deleted!\n";
	}
	system("pause");
	system("cls");
}

void edit_cont(char **str, int h, int contact_number)
{
	cout << contact_number << ". " << str[contact_number - 1] << endl;
	cout << "Edit contact to: \n";
	cin.getline(str[contact_number - 1], h);
	cout << "[+] Contact changed!\n";
	system("pause");
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}