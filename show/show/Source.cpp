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
	cout << str << endl;
}