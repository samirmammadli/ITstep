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

//����������� �����������
MyString::MyString(const MyString &str)
{
	this->length = str.length;
	this->symbols = new char[this->length];
	strcpy(this->symbols, str.symbols);
}

//����������
MyString::~MyString()
{
	delete[] symbols;
}

//������ ������
int MyString::Length() const
{
	return this->length - 1;
}

//�������� ������
void MyString::clear()
{
	delete this->symbols;
	this->length = 1;
	this->symbols = new char{ '\0' };
}

//������ �� ������
bool MyString::empty()
{
	if (symbols[0] == '\0')
		return true;
	else
		return false;
}

//������� char ������
char* MyString::c_str()
{
	return symbols;
}

//�������� �������� ���� �����
void MyString::Swap(MyString &str)
{
	swap(this->length, str.length);
	swap(symbols, str.symbols);
}

//�������� ��������� �� �������
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

//������� �������
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

//�������� �������
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

//����� ��������� � ������ � ������� �� ������
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

//���������� ���������=
MyString MyString::operator= (const MyString &str)
{
	this->length = str.length;
	delete[] this->symbols;
	this->symbols = new char[this->length];
	strcpy(this->symbols, str.symbols);
	return *this;

}

//���������� ���������+=
void MyString::operator+= (const MyString &str)
{
	this->length += str.Length();
	char * temp = new char[this->length];
	strcpy(temp, this->symbols);
	strcat(temp, str.symbols);
	delete[] this->symbols;
	this->symbols = temp;
}

//���������� ���������==
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

//���������� ���������<< ����� ������������� �������
ostream& operator<< (ostream &out, const MyString &str)
{
	out << str.symbols;
	return out;
}

//���������� ���������>> ����� ������������� �������
void operator>> (istream &in, MyString &str)
{
	
	
	delete[] str.symbols;
	str.symbols = new char[5000];
	in.getline(str.symbols, LONG_MAX);
	str.length = strlen(str.symbols) + 1;
	//return in;
}

////���������� ���������+ ����� ������������� �������
//MyString operator+ (const MyString &str1, const MyString &str2)
//{
//	int _length = str1.length + str2.length - 1;
//	char* tmp = new char[_length];
//	strcpy(tmp, str1.symbols);
//	strcat(tmp, str2.symbols);
//	return MyString(tmp);
//}

//���������� ���������+ ����� ������������� �������
MyString MyString::operator+ (const MyString &str)
{
	
	MyString temp;
	temp.length = length + str.length - 1;
	temp.symbols = new char[temp.length];
	strcpy(temp.symbols, symbols);
	strcat(temp.symbols, str.symbols);
	return temp;
}

