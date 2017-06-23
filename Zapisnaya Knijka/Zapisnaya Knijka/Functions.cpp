#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
using namespace std;


void disp_list(char **str, int w, short &col)
{
	COORDS(0, 2);
	cout << "Contacts:\n";
	for (int i = 0; i < w ; i++)
	{
		COORDS(0, i + 4);
		cout << i+1 << ". " << str[i] << "\t\t\t" << endl;
		if (i > 7)
			col = i+6;
	}
	COORDS(0, col);
}

void add_cont(char **&str, int &w, int h)
{
	char **temp = new char*[w+1];
	for (int i = 0; i < w+1; i++)
	{
		temp[i] = new char[h];
	}
	for (int i = 0; i < w; i++)
	{
		strcpy(temp[i], str[i]);
	}
	cout << "Please, input Name to new contact:\n";
	cin.getline(temp[w], h);
	for (int i = 0; i < w; i++)
	{
		delete[]str[i];
	}
	delete[]str;
	str = temp;
	w++;
	cout << "[+] New Contact Added!\n";
	system("pause");
	system("cls");
}

void sort_cont(char **str, int w, int h)
{
	char *temp = new char[h];
	for (int i = 0; i < w; i++)
	{
		for (int j = i+1; j < w; j++)
		{
			if (str[i][0] > str[j][0])
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
	else
	{
		char **temp_str = new char*[w - 1];
		for (int i = 0; i < w - 1; i++)
		{
			temp_str[i] = new char[h];
		}
		strcpy(str[contact_number - 1], str[w - 1]);
		for (int i = 0; i < w - 1; i++)
		{
			strcpy(temp_str[i], str[i]);
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