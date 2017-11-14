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
	memcpy(this->symbols, str, this->length);
}

MyString::MyString(string str)
{
	this->length = str.length() + 1;
	this->symbols = new char[this->length];
	memcpy(this->symbols, str.c_str(), this->length);
}

//Конструктор копирования
MyString::MyString(const MyString &str)
{
	this->length = str.length;
	this->symbols = new char[this->length];
	strcpy(this->symbols, str.symbols);
}

//Деструктор
MyString::~MyString()
{
	delete[] symbols;
}

//Длинна строки
int MyString::Length() const
{
	return this->length - 1;
}

//Очистить строку
void MyString::clear()
{
	delete[] this->symbols;
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
const char* const MyString::c_str()
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
void MyString::insert(int index, const MyString &str)
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
	else
	{
		exception e("Incorrect index!\n");
		throw(e);
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
		this->length = strlen(symbols) + 1;
	}
	else
	{
		exception e("Incorrect start or index!\n");
		throw(e);
	}
}

//Заменить символы
void MyString::replace(int start, int finish, const MyString &str)
{
	if (start >= 0 && start < this->Length() && finish > start && finish < this->Length() && finish - start < str.Length())
	{
		int j = 0;
		for (int i = start; i <= finish; i++)
		{
			this->symbols[i] = str.symbols[j++];
		}
	}
	else
	{
		exception e("Incorrect Indexex!\n");
			throw(e);
	}
}

//Найти подстроку в строке и вернуть ее индекс
int MyString::find(const MyString &str)
{
	int j;
	int StrLen = str.Length();
	if (StrLen < this->length)
	{
		for (int i = 0; i < this->length - 1; i++)
		{
			for (j = 0; j < StrLen; j++)
			{
				if (i + j >= this->length - 1) return -1;
				if (this->symbols[i + j] != str.symbols[j]) break;
			}
			if (j == StrLen && j != 0) return i;
		}
	}
	return -1;
}

//Перегрузка оператора=
MyString& MyString::operator= (const MyString &str)
{
	this->length = str.length;
	delete[] this->symbols;
	this->symbols = new char[this->length];
	strcpy(this->symbols, str.symbols);
	return *this;

}

//Перегрузка оператора+=
MyString& MyString::operator+= (const MyString &str)
{
	this->length += str.Length();
	char * temp = new char[this->length];
	strcpy(temp, this->symbols);
	strcat(temp, str.symbols);
	delete[] this->symbols;
	this->symbols = temp;
	return *this;
}

//Перегрузка оператора==
bool MyString::operator== (const MyString &str)
{
	bool match = true;
	if (str.Length() == this->Length())
	{
		for (int i = 0; i < this->Length(); i++)
		{
			if (this->symbols[i] != str.symbols[i])
				match = false;
		}
	}
	else
		match = false;

	return match;
}

//Перегрузка оператора!=
bool MyString::operator!=(const MyString &str)
{
	return !(*this == str);
}

//Перегрузка оператора>
bool MyString::operator> (const MyString &str)
{
	for (int i = 0; this->symbols[i] != '\0' && str.symbols[i] != '\0' ; i++)
	{
		if (this->symbols[i] > str.symbols[i])
			return true;
	}
	return false;
}

//Перегрузка оператора<
bool MyString::operator< (const MyString &str)
{
	return !(*this > str);
}

//Перегрузка оператора<< через дружественную функцию
ostream& operator<< (ostream &out, const MyString &str)
{
	out << str.symbols;
	return out;
}

//Перегрузка оператора>> через дружественную функцию
istream& operator>> (istream &in, MyString &str)
{
	
	char * temp = new char[5000];
	in.getline(temp, 5000);
	str.length = strlen(temp) + 1;
	delete[] str.symbols;
	str.symbols = new char[str.length];
	strcpy(str.symbols, temp);
	return in;
}

//Перегрузка оператора+
MyString MyString::operator+ (const MyString &str)
{
	MyString temp;
	temp.length = length + str.length - 1;
	temp.symbols = new char[temp.length];
	strcpy(temp.symbols, symbols);
	strcat(temp.symbols, str.symbols);
	return temp;
}

//Перегрузка оператора[]
char& MyString::operator[] (int index)
{
	exception e("Incorrect Index!\n");
	
	if (index >= this->length)
		throw(e);
	return this->symbols[index];
}








