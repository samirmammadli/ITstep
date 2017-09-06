#include "Student.h"



Student::Student()
{
	this->name = "Empty";
	this->surname = "Empty";
	this->phone = "Empty";
	this->age = 0;
	this->average = 0;
}
Student::Student(string name, string surname, string phone, int age, double average)
{
	if (age > 14 && age < 40 && average >= 0 && average <= 12)
	{
		this->name = name;
		this->surname = surname;
		this->phone = phone;
		this->age = age;
		this->average = average;
	}

}
string Student::GetName()
{
	return this->name;
}
string Student::GetSurname()
{
	return this->surname;
}
string Student::GetPhone()
{
	return this->phone;
}
int Student::GetAge()
{
	return this->age;
}
double Student::GetAverage()
{
	return this->average;
}
void Student::SetName(string name)
{
	this->name = name;
}
void Student::SetSurname(string surname)
{
	this->surname = surname;
}
void Student::SetPhone(string phone)
{
	this->phone = phone;
}
void Student::SetAge(int age)
{
	this->age = age;
}
void Student::SetAverage(double average)
{
	this->average = average;
}