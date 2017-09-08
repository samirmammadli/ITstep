#include "AcademyGroup.h"



AcademyGroup::AcademyGroup()
{
	//this->pSt.push_back(new Student("Empty", "Empty", "Empty", 0, 0));
}

AcademyGroup::AcademyGroup(string name, string surname, string phone, int age, double average)
{
	
	this->pSt.push_back(new Student(name, surname, phone, age, average));
}


AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < this->pSt.size(); i++)
	{
		delete pSt[i];
	}
}

void AcademyGroup::AddStudents(string name, string surname, string phone, int age, double average)
{
	this->pSt.push_back(new Student(name, surname, phone, age, average));
}

void AcademyGroup::AddStudents()
{

	int choose, temp;
	double temp_;
	string temp_str;

	this->pSt.push_back(new Student());

	cout << "Input Student`s name:\n";
	cin >> temp_str;
	this->pSt[this->pSt.size() - 1]->SetName(temp_str);

	cout << "Input Student`s surname:\n";
	cin >> temp_str;
	this->pSt[this->pSt.size() - 1]->SetSurname(temp_str);

	cout << "Input Student`s phone:\n";
	cin >> temp_str;
	this->pSt[this->pSt.size() - 1]->SetPhone(temp_str);

	cout << "Input Student`s age:\n";
	cin >> temp;
	if (temp > 14 && temp < 56)
		this->pSt[this->pSt.size() - 1]->SetAge(temp);
	else
	{
		printf("Invalid age! (from 15 to 55)\n");
		system("pause");
		this->pSt.erase(pSt.end() - 1);
		return;
	}


	cout << "Input Student`s average:\n";
	cin >> temp_;
	if (temp_ >= 0 && temp_ <= 12.0)
		this->pSt[this->pSt.size() - 1]->SetAverage(temp_);
	else
	{
		printf("Invalid average! (from 0 to 12)\n");
		this->pSt.erase(pSt.end() - 1);
		system("pause");
		return;
	}
	cout << "Student Added!\n";
	system("pause");
}

void AcademyGroup::DeleteStudent(int student_number)
{
	student_number--;

	if (student_number >= 0 && student_number < this->pSt.size())
	{
		pSt.erase(pSt.begin() + student_number);
		cout << "Student successfully deleted!\n";
	}
	else
		cout << "Invalid Student Number!\n";
}
void AcademyGroup::EditStudent(int student_number)
{
	student_number--;
	if (student_number >= 0 && student_number < this->pSt.size())
	{
		int choose, temp;
		double temp_;
		string temp_str;
		cout << "\nNumber:     " << "Name:          " << "Surname:          " << "Age:        " << "Phone:                " << "Average:\n" << endl;
		printf_s("%-12d%-15s%-18s%-12d%-22s%.2f\n\n", student_number + 1, this->pSt[student_number]->GetName().c_str(), this->pSt[student_number]->GetSurname().c_str(), this->pSt[student_number]->GetAge(), this->pSt[student_number]->GetPhone().c_str(), this->pSt[student_number]->GetAverage());
		cout << "1. Edit name.\n";
		cout << "2. Edit surname.\n";
		cout << "3. Edit phone.\n";
		cout << "4. Edit age.\n";
		cout << "5. Edit average.\n";
		cout << "6. Back to menu.\n";
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
		case 6:
			return;
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
	for (int i = 0; i < pSt.size(); i++)
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
	for (int i = 0; i < pSt.size(); i++)
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
		for (int i = 0; i < this->pSt.size(); i++)
		{
			for (int j = i; j < this->pSt.size(); j++)
			{
				if (this->pSt[i]->GetName() > this->pSt[j]->GetName())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case SURNAME:
		for (int i = 0; i < this->pSt.size(); i++)
		{
			for (int j = i; j < this->pSt.size(); j++)
			{
				if (this->pSt[i]->GetSurname() > this->pSt[j]->GetSurname())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case AGE:
		for (int i = 0; i < this->pSt.size(); i++)
		{
			for (int j = i; j < this->pSt.size(); j++)
			{
				if (this->pSt[i]->GetAge() > this->pSt[j]->GetAge())
				{
					swap(this->pSt[i], this->pSt[j]);
				}
			}
		}
		break;
	case AVERAGE:
		for (int i = 0; i < this->pSt.size(); i++)
		{
			for (int j = i; j < this->pSt.size(); j++)
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
