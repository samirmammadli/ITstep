#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;


class MyString
{
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
	const char* const c_str();
	//�������� �������� ���� �����
	void Swap(MyString &str);
	//�������� ��������� �� �������
	void insert(int index,const MyString &str);
	//������� �������
	void erase(int start, int count);
	//�������� �������
	void replace(int start, int finish,const MyString &str);
	//����� ��������� � ������ � ������� �� ������
	int find(const MyString &str);
	//���������� ���������=
	MyString& operator= (const MyString &str);
	//���������� ���������+=
	MyString& operator+= (const MyString &str);
	//���������� ���������==
	bool operator== (const MyString &str);
	//���������� ���������!=
	bool operator!=(const MyString &str);
	//���������� ���������>
	bool operator> (const MyString &str);
	//���������� ���������<
	bool MyString::operator< (const MyString &str);
	//���������� ���������<< ����� ������������� �������
	friend ostream& operator<< (ostream &out, const MyString &str);
	//���������� ���������>> ����� ������������� �������
	friend istream& operator>> (istream &in, MyString &str);
	//���������� ���������+
	MyString operator+ (const MyString &str);
	//���������� ���������[]
	char& operator[] (int index);
};