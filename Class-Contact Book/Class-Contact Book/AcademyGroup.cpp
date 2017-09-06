#include "AcademyGroup.h"



AcademyGroup::AcademyGroup()
{
	this->count = 10;
	this->curr_student_count = 0;
	this->pSt = new Student*[this->count];
	for (int i = 0; i < this->count; i++)
	{
		this->pSt[i] = new Student;
	}
}


AcademyGroup::~AcademyGroup()
{

	for (int i = 0; i < this->count; i++)
	{
		delete pSt[i];
	}
}

void AcademyGroup::AddStudents(string name, string surname, string phone, int age, double average)
{
	if (this->curr_student_count == this->count - 1)
		this->AddSpace();

	this->pSt[this->curr_student_count]->SetName(name);
	this->pSt[this->curr_student_count]->SetSurname(surname);
	this->pSt[this->curr_student_count]->SetPhone(phone);
	this->pSt[this->curr_student_count]->SetAge(age);
	this->pSt[this->curr_student_count]->SetAverage(average);
	this->curr_student_count++;
}

void AcademyGroup::AddSpace()
{
	Student **temp = new Student*[count + 10];
	for (int i = 0; i < count + 10; i++)
	{
		temp[i] = new Student;
	}
	memcpy(temp, this->pSt, this->count * sizeof(Student*));
	this->count += 10;
	delete[] this->pSt;
	pSt = temp;
}

void AcademyGroup:: DeleteStudent(int student_number)
{
	student_number -= 1;
	if (student_number >=0 && student_number < this->curr_student_count)
	{
		
		for (int i = student_number; i < this->curr_student_count; i++)
		{
			if (i + 1 < this->curr_student_count)
			{
				this->pSt[i] = this->pSt[i + 1];
			}
		}
		this->curr_student_count -= 1;
		pSt[this->curr_student_count] = new Student;
	}
}
void AcademyGroup::EditStudent()
{
}

void AcademyGroup::Print()
{
	cout << "Number:     " << "Name:          " << "Surname:          " << "Age:        " << "Phone:                " << "Average:\n" << endl;
	for (int i = 0; i < curr_student_count; i++)
	{
		cout << "__________________________________________________________________________________________________________\n";
		printf_s("%-12d%-15s%-18s%-12d%-22s%.2f", i + 1, this->pSt[i]->GetName().c_str(), this->pSt[i]->GetSurname().c_str(), this->pSt[i]->GetAge(), this->pSt[i]->GetPhone().c_str(), this->pSt[i]->GetAverage());
		cout << endl;
	}
}

void AcademyGroup::FindStudent()
{
}

void AcademyGroup::Sort()
{
}
