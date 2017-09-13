#include "MyString.h"



void main()
{


	MyString str1("Samir Mammadli");
	MyString str2 = "Samir";
	MyString asdw{};


	


	MyString str4 = "Salam";
	MyString str5 = "Sagol";
	MyString str6 = "Necesen";
	MyString str7 = "Pis deilem";
	MyString str8 = "Pis deilem";

	MyString str3;
	str3 = str1 + str2 + str4 + str5 +str6 + str7 + str8;
	cout << str3 << endl;
	str3 += str1;
	cout << str3 << endl;
	if (str7 == str8)
	{
		cout << "Match\n";
	}
	else
		cout << "Not match\n";

	cout << str1 + str2 << endl;
	cout << str1 << endl;


}