#include "MyString.h"



MyString::MyString()
{
	symbols = nullptr;
	this->length = 0;
}
MyString::MyString(char *str) : MyString()
{
	
	//this->length = 0;
	for (int i = 0; str[i] != '\0' ; i++)
	{
		this->length++;
	}
	cout << this->length;
	this->length++;
	this->symbols = new char[this->length];
	memcpy(symbols, str, this->length * sizeof(char));
	
	
}
MyString::MyString(string str)
{

}
//����������� �����������
MyString::MyString(MyString &str)
{

}
//����������
MyString::~MyString()
{
	//delete[] symbols;
}

//������ ������
int MyString::Length()
{
	return 0;
}
//�������� ������
void MyString::clear()
{
	0;
}
//������ �� ������
bool MyString::empty()
{
	return 0;
}
//������� char ������
char* MyString::c_str()
{
	return symbols;
}
//�������� �������� ���� �����
void MyString::swap(MyString &str)
{

}
//�������� ��������� �� �������
void MyString::insert(int index, MyString str)
{
	cout << this->symbols << endl;
}
//������� �������
void MyString::erase(int start, int count)
{

}
//�������� �������
void MyString::replace(int start, int finish, MyString str)
{

}
//����� ��������� � ������ � ������� �� ������
int MyString::find(const MyString str)
{
	return 0;
}
