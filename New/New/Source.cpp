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


template <typename T>
void samir (T index)
{
	cout << index << endl;
}

Test* Test::obj = new Test;

struct point {
	int x;
	int y;
};

void main()
{
	/*Test *p = Test::Obj();


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
	cout << a << endl;*/

	point a[4] = {};

	a[1].x = 10;
	a[1].y = 10;


	int x = 1;
	int y = 1;

	int ax = 0;
	int ay = 1;

	int tempx = ax - x;
	int tempy = ay - y;
	ax -= tempx;
	ay -= tempy;
	

	cout << ax << endl;
	cout << ay << endl;


}