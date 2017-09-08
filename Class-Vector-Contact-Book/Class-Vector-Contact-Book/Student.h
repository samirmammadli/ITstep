#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Student {
	string name;
	string surname;
	string phone;
	int age;
	double average;
public:
	Student();
	Student(string name, string surname, string phone, int age, double average);
	string GetName();
	string GetSurname();
	string GetPhone();
	int GetAge();
	double GetAverage();
	void SetName(string name);
	void SetSurname(string surname);
	void SetPhone(string phone);
	void SetAge(int age);
	void SetAverage(double average);
};
