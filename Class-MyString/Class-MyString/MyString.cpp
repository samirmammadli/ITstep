#include "MyString.h"



MyString::MyString()
{
	this->symbols = new char{ '\0' };
	this->length = 1;
}

MyString::MyString(char *str)
{
	this->length = strlen(str) + 1;
	this->symbols = new char[this->length];
	memcpy(symbols, str, this->length);
}

MyString::MyString(string str)
{
	this->length = str.length() + 1;
	this->symbols = new char[this->length];
	memcpy(this->symbols, str.c_str(), this->length);
}

//Конструктор копирования
MyString::MyString(MyString &str)
{
	this->length = str.Length() + 1;
	this->symbols = new char[this->length];
	strcpy(this->symbols, str.symbols);
}

//Деструктор
MyString::~MyString()
{
	delete[] symbols;
}

//Длинна строки
int MyString::Length()
{
	return this->length - 1;
}

//Очистить строку
void MyString::clear()
{
	delete this->symbols;
	this->length = 1;
	this->symbols = new char{ '\0' };
}

//Пустая ли строка
bool MyString::empty()
{
	if (symbols[0] == '\0')
		return true;
	else
		return false;
}

//Вернуть char массив
char* MyString::c_str()
{
	return symbols;
}

//Обменять значения двух строк
void MyString::Swap(MyString &str)
{
	swap(this->length, str.length);
	swap(symbols, str.symbols);
}

//Вставить подстроку по индексу
void MyString::insert(int index, MyString str)
{
	if (index >= 0 && index < this->length)
	{
		int count = 0;
		this->length += str.Length();
		char * temp = new char[this->length];
		for (int i = 0; i < this->length; i++)
		{
			if (i == index)
			{
				for (int j = 0; j < str.Length(); j++)
				{
					temp[i++] = str.symbols[j];
					count++;
				}
				i--;
			}
			else
				temp[i] = this->symbols[i - count];
		}
		delete[] this->symbols;
		this->symbols = temp;
	}
}

//Удалить символы
void MyString::erase(int start, int count)
{
	if (start + count < this->length && start >= 0 && count >= 0)
	{
		for (int i = start; i + count < this->length; i++)
		{
			symbols[i] = symbols[i + count];
		}
	}
}

//Заменить символы
void MyString::replace(int start, int finish, MyString str)
{
	if (start >= 0 && start < this->Length() && finish > start && finish < this->Length() && finish - start < str.Length())
	{
		int j = 0;
		for (int i = start; i <= finish; i++)
		{
			this->symbols[i] = str.symbols[j++];
		}
	}
}

//Найти подстроку в строке и вернуть ее индекс
int MyString::find(MyString str)
{
	int j;
	int StrLen = str.Length();
	if (StrLen <= this->length - 1)
	{
		for (int i = 0; i < this->length - 1; i++)
		{
			for (j = 0; j < StrLen; j++)
			{
				if (this->symbols[i + j] != str.symbols[j]) break;
			}
			if (j == StrLen) return i;
		}
		return -1;
	}
	else
	return -1;
}
