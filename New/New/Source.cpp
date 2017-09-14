#pragma once
#include <iostream>
#include <string>
using namespace std;



class Test {
	int x;
	int y;
	static Test * obj;
	
	Test(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
public:
	static Test* Obj()
	{
		return obj;
	}
};




Test* Test::obj = new Test;

void main()
{

	Test *p = Test::Obj();


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