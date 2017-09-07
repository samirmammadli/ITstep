#include "Student.h"
#include "AcademyGroup.h"



void main()
{
	AcademyGroup test;
	test.AddStudents("Samir", "Mammadli", "+994557099110", 31, 12);
	test.AddStudents("Zahid", "Abbasli", "+994557892564", 27, 8);
	test.AddStudents("Kamal", "Jafarov", "+994503481574", 28, 6);
	test.AddStudents("Rufat", "Mammadov", "+994557099457", 31, 11);
	test.AddStudents("Vulgar", "Yusubov", "+994706826060", 27, 5);
	test.AddStudents("Ilgar", "Ahmedov", "+994715593302", 28, 7.2);
	

	test.DeleteStudent(0);
	test.Print();
}