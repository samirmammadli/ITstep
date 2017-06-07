#include <iostream>
#include <string>
using namespace std;

void main()
{
	string str;
	str = "Salam, ay Brat!";
	getline(cin, str);
	cout << str.length() << endl;  // Показывает длину строки
	cout << str.size() << endl;   // Показывает длину строки
	cout << str << endl;  // Выводит строку на экран.
	str.empty();  //Правда, если строка пустая, ложь если строка не пустая.
	const char *str2 = str.c_str();
	cout << str.c_str() << endl;
}