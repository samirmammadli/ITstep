#include "AcademyGroup.h"



AcademyGroup::AcademyGroup()
{
	this->count = 10;
	this->curr_student_count = 0;
	this->pSt = new Student*[this->count];
	for (int i = 0; i < this->count; i++)
	{
		this->pSt[i] = nullptr;
	}
}

AcademyGroup::AcademyGroup(string name, string surname, string phone, int age, double average)
{
	this->count = 10;
	this->curr_student_count = 0;
	this->pSt = new Student*[this->count];
	for (int i = 0; i < this->count; i++)
	{
		this->pSt[i] = nullptr;
	}
	this->pSt[curr_student_count] = new Student(name, surname, phone, age, average);
	this->curr_student_count++;
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

	this->pSt[curr_student_count] = new Student(name, surname, phone, age, average);
	this->curr_student_count++;
}

void AcademyGroup::AddStudents()
{
	if (this->curr_student_count == this->count - 1)
		this->AddSpace();

	int choose, temp;
	double temp_;
	string temp_str;

	this->pSt[curr_student_count] = new Student;

	cout << "Input Student`s name:\n";
	cin >> temp_str;
	this->pSt[curr_student_count]->SetName(temp_str);

	cout << "Input Student`s surname:\n";
	cin >> temp_str;
	this->pSt[curr_student_count]->SetSurname(temp_str);

	cout << "Input Student`s phone:\n";
	cin >> temp_str;
	this->pSt[curr_student_count]->SetPhone(temp_str);

	cout << "Input Student`s age:\n";
	cin >> temp;
	if (temp > 14 && temp < 56)
		this->pSt[curr_student_count]->SetAge(temp);
	else
	{
		printf("Invalid age! (from 15 to 55)\n");
		system("pause");
		delete this->pSt[curr_student_count];
		this->pSt[curr_student_count] = nullptr;
		return;
	}


	cout << "Input Student`s average:\n";
	cin >> temp_;
	if (temp_ >= 0 && temp_ <= 12.0)
		this->pSt[curr_student_count]->SetAverage(temp_);
	else
	{
		printf("Invalid average! (from 0 to 12)\n");
		delete this->pSt[curr_student_count];
		this->pSt[curr_student_count] = nullptr;
		system("pause");
		return;
	}
	this->curr_student_count++;
	cout << "Student Added!\n";
	system("pause");
}

void AcademyGroup::AddSpace()
{
	Student **temp = new Student*[count + 10];
	for (int i = 0; i < count + 10; i++)
	{
		temp[i] = nullptr;
	}
	memcpy(temp, this->pSt, this->count * sizeof(Student*));
	this->count += 10;
	delete[] this->pSt;
	pSt = temp;
}

void AcademyGroup:: DeleteStudent(int student_number)
{
	student_number--;
	
	if (student_number >=0 && student_number < this->curr_student_count)
	{
		delete pSt[student_number];
		pSt[student_number] = nullptr;
		for (int i = student_number; i < this->curr_student_count; i++)
		{
			if (i + 1 < this->curr_student_count)
			{
				this->pSt[i] = this->pSt[i + 1];
				this->pSt[i + 1] = nullptr;
			}
		}
		this->curr_student_count--;
		cout << "Student successfully deleted!\n";
	}
	else
		cout << "Invalid Student Number!\n";
}
void AcademyGroup::EditStudent(int student_number)
{
	student_number--;
	if (student_number >= 0 && student_number < this->curr_student_count)
	{
		int choose, temp;
		double temp_;
		string temp_str;
		cout << "1. Edit name.\n";
		cout << "2. Edit surname.\n";
		cout << "3. Edit phone.\n";
		cout << "4. Edit age.\n";
		cout << "5. Edit average.\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Input Student`s name:\n";
			cin >> temp_str;
			this->pSt[student_number]->SetName(temp_str);
			break;
		case 2:
			cout << "Input Student`s surname:\n";
			cin >> temp_str;
			this->pSt[student_number]->SetSurname(temp_str);
			break;
		case 3:
			cout << "Input Student`s phone:\n";
			cin >> temp_str;
			this->pSt[student_number]->SetPhone(temp_str);
			break;
		case 4:
			cout << "Input Student`s age:\n";
			cin >> temp;
			temp > 14 && temp < 56 ? this->pSt[student_number]->SetAge(temp) : printf("Invalid age! (from 15 to 55)\n");
			break;
		case 5:
			cout << "Input Student`s average:\n";
			cin >> temp_;
			temp_ >= 0 && temp_ <= 12.0 ? this->pSt[student_number]->SetAverage(temp_) : printf("Invalid average! (from 0 to 12)\n");
			break;
		default:
			cout << "Invalid Operation Number!\n";
		}
	}
	else
		cout << "Invalid Student Number!\n";

	system("pause");
}

void AcademyGroup::Print()
{
	cout << "Number:     " << "Name:          " << "Surname:          " << "Age:        " << "Phone:                " << "Average:\n" << endl;
	for (int i = 0; i < curr_student_count; i++)
	{
		cout << "________________________________________________________________________________________\n";
		printf_s("%-12d%-15s%-18s%-12d%-22s%.2f\n", i + 1, this->pSt[i]->GetName().c_str(), this->pSt[i]->GetSurname().c_str(), this->pSt[i]->GetAge(), this->pSt[i]->GetPhone().c_str(), this->pSt[i]->GetAverage());
	}
	cout << "________________________________________________________________________________________\n";
	system("pause");
}

void AcademyGroup::FindStudent(string find)
{
	int size;
	cout << "Number:     " << "Name:          " << "Surname:          " << "Age:        " << "Phone:                " << "Average:\n" << endl;
	for (int i = 0; i < curr_student_count; i++)
	{
		size = this->pSt[i]->GetName().length();
		if (this->pSt[i]->GetName().rfind(find, size) != find.npos)
		{
		
			cout << "__________________________________________________________________________________________________________\n";
			printf_s("%-12d%-15s%-18s%-12d%-22s%.2f", i + 1, this->pSt[i]->GetName().c_str(), this->pSt[i]->GetSurname().c_str(), this->pSt[i]->GetAge(), this->pSt[i]->GetPhone().c_str(), this->pSt[i]->GetAverage());
			cout << endl;
		}
	}
	cout << "__________________________________________________________________________________________________________\n";
}

void AcademyGroup::Sort(Sorting sort_by)
{
	switch (sort_by)
	{
	case NAME:
		for (int i = 0; i < this->curr_student_count; i++)
		{
			for (int j = i; j < this->curr_student_count; j++)
			{
				if (this->pSt[i]->GetName() > this->pSt[j]->GetName())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case SURNAME:
		for (int i = 0; i < this->curr_student_count; i++)
		{
			for (int j = i; j < this->curr_student_count; j++)
			{
				if (this->pSt[i]->GetSurname() > this->pSt[j]->GetSurname())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case AGE:
		for (int i = 0; i < this->curr_student_count; i++)
		{
			for (int j = i; j < this->curr_student_count; j++)
			{
				if (this->pSt[i]->GetAge() > this->pSt[j]->GetAge())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case AVERAGE:
		for (int i = 0; i < this->curr_student_count; i++)
		{
			for (int j = i; j < this->curr_student_count; j++)
			{
				if (this->pSt[i]->GetAverage() > this->pSt[j]->GetAverage())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	}
}
