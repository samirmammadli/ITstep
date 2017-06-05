#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

void add_array(char *str, char *str2, int size);

void main()
{
	/*string cmd_str;
	char str[1000];
	cout << "Vvedite nazvanie Wi-Fi seti: ";
	cin.getline(str, 1000);
	cmd_str = "netsh wlan show profiles name=";
	cmd_str += str;
	cmd_str += " key=clear";

	system(cmd_str.c_str());
	_getch();*/

	string cmd_str;
	const int size = 100;
	char str[size] = "netsh wlan show profiles name=\"", str2[30];
	cout << "Vvedite nazvanie Wi-Fi seti: ";
	cin.getline(str2, 30);
	add_array(str, str2, size);
	char str3[12] = "\" key=clear";
	add_array(str, str3, size);
	getline(cin, cmd_str);
	cout << cmd_str << endl;
	_getch();
}

void add_array(char *str, char *str2, int size)
{
	bool end = false;
	for (int i = 0; !end; i++)
	{
		str[i] == '\0' ? end = true : 0;
		if (end)
		{
			for (int n = 0; n < 100 && str2[n] != '\0'; n++)
			{
				str[i] = str2[n];
				i++;
			}
		}
	}
}
