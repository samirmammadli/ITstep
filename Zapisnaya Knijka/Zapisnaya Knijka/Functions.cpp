#include <iostream>
#include <conio.h>
using namespace std;

void disp_list(char **str, int w)
{
	for (int i = 0; i < w ; i++)
	{
		cout << i+1 << ". " << str[i] << endl;
	}
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
}

void delete_cont(char **&str, int &w, int h, int contact_number)
{
	char **temp_str = new char*[w-1];
	for (int i = 0; i < w-1; i++)
	{
		temp_str[i] = new char[h];
	}
	strcpy(str[contact_number-1], str[w-1]);
	for (int i = 0; i < w-1; i++)
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
	system("pause");
}

void edit_cont(char **str, int h, int contact_number)
{
	cout << contact_number << ". " << str[contact_number - 1] << endl;
	cout << "Edit contact to: \n";
	cin.getline(str[contact_number - 1], h);
	cout << "[+] Contact changed!\n";
	system("pause");
}