#pragma once
#include <iostream>
#include <string>
using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");
	string lesh;
	lesh = "Salam aleykum";
	string temp = "aleyakum";

	unsigned long long int  a;
	if (lesh.rfind(temp, lesh.length()) != lesh.npos)
		cout << "Nashel!\n";
	else
		cout << "Ne nawel!\n";

	a = lesh.rfind(temp, lesh.length());
	cout << lesh.npos << endl;
	cout << a << endl;

	


}