#pragma once
#include "Student.h"
class AcademyGroup
{
	Student** pSt;
	int curr_student_count;
	int count;
public:
	AcademyGroup();
	~AcademyGroup();
	void AddStudents(string name, string surname, string phone, int age, double average);
	void AddSpace();
	void DeleteStudent(int student_number);
	void EditStudent(int number, string name, string surname, string phone, int age, double average);
	void Print();
	void FindStudent();
	void Sort();
};

