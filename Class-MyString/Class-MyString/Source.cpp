#include "MyString.h"



void main()
{
	MyString str1("Samir Mammadli");
	MyString str2("saffhj");
	MyString str3;
	str3 = str1 + str2;
	cout << str3.c_str() << endl;
	/*str1 = str2 + str3;
	cout << str1.c_str() << endl;*/

}