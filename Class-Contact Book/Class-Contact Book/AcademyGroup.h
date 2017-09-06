#pragma once
#include "Student.h"
class AcademyGroup
{
	Student** pSt;
	int count;
public:
	AcademyGroup();
	~AcademyGroup();
	void AddStudents();
	void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
};

