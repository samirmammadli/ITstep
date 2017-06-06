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
	cout << str << endl;
}