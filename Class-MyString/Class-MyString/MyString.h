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
	char* c_str();
	//Обменять значения двух строк
	void Swap(MyString &str);
	//Вставить подстроку по индексу
	void insert(int index, MyString str);
	//Удалить символы
	void erase(int start, int count);
	//Заменить символы
	void replace(int start, int finish, MyString str);
	//Найти подстроку в строке и вернуть ее индекс
	int find(MyString str);
	//Перегрузка оператора=
	MyString operator= (const MyString &str);
	//Перегрузка оператора+=
	void operator+= (const MyString &str);
	//Перегрузка оператора==
	bool operator== (const MyString &str);
	//Перегрузка оператора<< через дружественную функцию
	friend ostream& operator<< (ostream &out, const MyString &str);
	//Перегрузка оператора>> через дружественную функцию
	friend void operator>> (istream &in, MyString &str);
	
	
	//Перегрузка оператора+ через дружественную функцию
	//friend MyString operator+ (const MyString &str1, const MyString &str2);


	MyString operator+ (const MyString &str);
};