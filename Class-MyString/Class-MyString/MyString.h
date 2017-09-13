#pragma once
#include <iostream>
#include <string>
using namespace std;


class MyString
{
	size_t npos;
	size_t str_max_size = 4294967291;
	char* symbols;
	int length = 0;

public:
	
	MyString();
	MyString(char *str);
	MyString(string str);
	//����������� �����������
	MyString(const MyString &str);
	//����������
	~MyString();

	//������ ������
	int Length() const;
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
	//���������� ���������=
	MyString operator= (const MyString &str);
	//���������� ���������+=
	void operator+= (const MyString &str);
	//���������� ���������==
	bool operator== (const MyString &str);
	//���������� ���������<< ����� ������������� �������
	friend ostream& operator<< (ostream &out, const MyString &str);
	//���������� ���������>> ����� ������������� �������
	friend void operator>> (istream &in, MyString &str);
	
	
	//���������� ���������+ ����� ������������� �������
	//friend MyString operator+ (const MyString &str1, const MyString &str2);


	MyString operator+ (const MyString &str);
};