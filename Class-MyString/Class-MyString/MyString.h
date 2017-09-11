#pragma once
#include <iostream>
#include <string>
using namespace std;


class MyString
{
	char* symbols;
	int length;

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
	void swap(MyString &str);
	//�������� ��������� �� �������
	void insert(int index, MyString str);
	//������� �������
	void erase(int start, int count);
	//�������� �������
	void replace(int start, int finish, MyString str);
	//����� ��������� � ������ � ������� �� ������
	int find(const MyString str);
};


