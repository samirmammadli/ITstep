#include "MyString.h"



void main()
{
	MyString str1("Samir Mammadli");
	MyString str2 = "Rufat";
	MyString str3;
	MyString str4 = "None";
	MyString str5 = "Hello World";
	MyString str6 = "World";
	MyString str7 = "People";
	MyString str8 = "test";

	cout << "Find \"Mamma\" in \"Samir Mammadli\":   " << str1.find("Samir Mammadli\0") << endl;
	try { str1.replace(1, 4, str8); }
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Repalce \"Samir Mammadli\" to \"test\", start: 1, finish 4: " << str1 << endl;

	str5.insert(6, "People ");
	cout << "Insert \"People \" in \"Hello World\" by index 6:     " << str5 << endl;

	cout << "str1 + str2:  " <<  str1 + str2 << endl;
	cout << "str1:  " << str1 << endl;
	cout << "str2:  " << str2 << endl;
	str7 += str8;
	cout << "str7+= str8:  " << str7 << endl;



	if (str1 > str2)
		cout << "str1 > str2\n";
	else
		cout << "str1 <str2\n";


	if (str1 < str2)
		cout << "str1 < str2\n";
	else
		cout << "str1 > str2\n";

	if (str7 == str8)
	{
		cout << "Match\n";
	}
	else
		cout << "Not match\n";


	if (str7 != str8)
	{
		cout << "Match\n";
	}
	else
		cout << "Not match\n";

	str1[2] = 'u';
	cout << str1[2] << endl;

	cout << str1.c_str() << endl;
	cout << str1 << endl;

	str1 = "Hello World!\n";

	try
	{
		str1.erase(0, 6);
		cout << str1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}



	//Error
	try
	{
		str1.erase(0, 8);
		cout << str1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}


	//Error
	try
	{
		cout << str1[22] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	//Error
	try
	{
		str1.insert(0, "Test Test Test");
		cout << str1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}


	
	
}