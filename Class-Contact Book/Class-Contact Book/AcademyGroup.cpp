#include "AcademyGroup.h"



AcademyGroup::AcademyGroup()
{
	this->count = 10;
	this->pSt = new Student*[count];
	for (int i = 0; i < this->count; i++)
	{
		this->pSt[i] = new Student;
	}
}


AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < this->count; i++)
	{
		delete[]pSt[i];
	}
}

void AcademyGroup::AddStudents()
{

}

void AcademyGroup:: DeleteStudent()
{
}

void AcademyGroup::EditStudent()
{
}

void AcademyGroup::Print()
{
}

void AcademyGroup::FindStudent()
{
}

void AcademyGroup::Sort()
{
}
