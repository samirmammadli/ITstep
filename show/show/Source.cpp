#include <iostream>
#include <string>
using namespace std;

void main()
{
	string str;
	str = "Salam, ay Brat!";
	getline(cin, str);
	cout << str.length() << endl;  // ���������� ����� ������
	cout << str.size() << endl;   // ���������� ����� ������
	cout << str << endl;  // ������� ������ �� �����.
	str.empty();  //������, ���� ������ ������, ���� ���� ������ �� ������.
	const char *str2 = str.c_str();
	cout << str.c_str() << endl;
}