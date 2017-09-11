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
//Конструктор копирования
MyString::MyString(MyString &str)
{

}
//Деструктор
MyString::~MyString()
{
	//delete[] symbols;
}

//Длинна строки
int MyString::Length()
{
	return 0;
}
//Очистить строку
void MyString::clear()
{
	0;
}
//Пустая ли строка
bool MyString::empty()
{
	return 0;
}
//Вернуть char массив
char* MyString::c_str()
{
	return symbols;
}
//Обменять значения двух строк
void MyString::swap(MyString &str)
{

}
//Вставить подстроку по индексу
void MyString::insert(int index, MyString str)
{
	cout << this->symbols << endl;
}
//Удалить символы
void MyString::erase(int start, int count)
{

}
//Заменить символы
void MyString::replace(int start, int finish, MyString str)
{

}
//Найти подстроку в строке и вернуть ее индекс
int MyString::find(const MyString str)
{
	return 0;
}
