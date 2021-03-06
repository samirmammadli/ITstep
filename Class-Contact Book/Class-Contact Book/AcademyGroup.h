#pragma once
#include "Student.h"

enum Sorting {
	NAME,
	SURNAME,
	AGE,
	AVERAGE
};

class AcademyGroup
{
	Student** pSt;
	int curr_student_count;
	int count;
public:
	AcademyGroup();
	AcademyGroup(string name, string surname, string phone, int age, double average);
	~AcademyGroup();
	void AddStudents(string name, string surname, string phone, int age, double average);
	void AddStudents();
	void AddSpace();
	void DeleteStudent(int student_number);
	void EditStudent(int student_number);
	void Print();
	void FindStudent(string find);
	void Sort(Sorting sort_by);
};

