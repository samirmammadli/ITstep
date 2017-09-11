#include "MyString.h"


void main()
{
	char testik[6]{ "Samir" };
	MyString test(testik);
	cout << test.c_str() << endl;
	
}