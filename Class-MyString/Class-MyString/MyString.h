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
	//Конструктор копирования
	MyString(const MyString &str);
	//Деструктор
	~MyString();

	//Длинна строки
	int Length() const;
	//Очистить строку
	void clear();
	//Пустая ли строка
	bool empty();
	//Вернуть char массив
	const char* const c_str();
	//Обменять значения двух строк
	void Swap(MyString &str);
	//Вставить подстроку по индексу
	void insert(int index,const MyString &str);
	//Удалить символы
	void erase(int start, int count);
	//Заменить символы
	void replace(int start, int finish,const MyString &str);
	//Найти подстроку в строке и вернуть ее индекс
	int find(const MyString &str);
	//Перегрузка оператора=
	MyString& operator= (const MyString &str);
	//Перегрузка оператора+=
	MyString& operator+= (const MyString &str);
	//Перегрузка оператора==
	bool operator== (const MyString &str);
	//Перегрузка оператора!=
	bool operator!=(const MyString &str);
	//Перегрузка оператора>
	bool operator> (const MyString &str);
	//Перегрузка оператора<
	bool MyString::operator< (const MyString &str);
	//Перегрузка оператора<< через дружественную функцию
	friend ostream& operator<< (ostream &out, const MyString &str);
	//Перегрузка оператора>> через дружественную функцию
	friend istream& operator>> (istream &in, MyString &str);
	//Перегрузка оператора+
	MyString operator+ (const MyString &str);
	//Перегрузка оператора[]
	char& operator[] (int index);
};