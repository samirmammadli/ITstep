#pragma once
#include <iostream>
#include <string>
using namespace std;


class MyString
{
	size_t npos;
	char* symbols;
	int length = 0;

public:
	MyString();
	MyString(char *str);
	MyString(string str);
	//����������� �����������
	MyString(MyString &str);
	//����������
	~MyString();

	//������ ������
	int Length();
	//�������� ������
	void clear();
	//������ �� ������
	bool empty();
	//������� char ������
	char* c_str();
	//�������� �������� ���� �����
	void Swap(MyString &str);
	//�������� ��������� �� �������
	void insert(int index, MyString str);
	//������� �������
	void erase(int start, int count);
	//�������� �������
	void replace(int start, int finish, MyString str);
	//����� ��������� � ������ � ������� �� ������
	int find(MyString str);

	friend MyString operator+ (const MyString &str1, const MyString &str2);
};