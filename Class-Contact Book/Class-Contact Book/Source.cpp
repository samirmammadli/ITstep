#include "Student.h"
#include "AcademyGroup.h"



void main()
{
	int oper = 0;
	AcademyGroup Group1("Tahir", "Mammadov", "+994557099110", 31, 12);
	Group1.AddStudents("Samir", "Mammadli", "+994557099110", 31, 12);
	Group1.AddStudents("Zahid", "Abbasli", "+994557892564", 27, 8);
	Group1.AddStudents("Kamal", "Jafarov", "+994503481574", 28, 6);
	Group1.AddStudents("Rufat", "Mammadov", "+994557099457", 31, 11);
	Group1.AddStudents("Vulgar", "Yusubov", "+994706826060", 27, 5);
	Group1.AddStudents("Ilgar", "Ahmedov", "+994715593302", 28, 7.2);


	while (true)
	{
		system("cls");
		cout << "1. Add student.\n";
		cout << "2. Edit student.\n";
		cout << "3. Find student.\n";
		cout << "4. Sort students.\n";
		cout << "5. Print students.\n";
		cout << "6. Delete student.\n";
		cout << "7. Exit.\n";
		cin >> oper;

		if (oper == 1)
		{
			system("cls");
			Group1.AddStudents();
		}
			

		else if (oper == 2)
		{
			system("cls");
			int number;
			cout << "Enter Studen`s number: ";
			cin >> number;
			Group1.EditStudent(number);
			system("cls");
		}
			

		else if (oper == 3)
		{
			system("cls");
			string name;
			cout << "Input Student`s name: ";
			cin >> name;
			Group1.FindStudent(name);
			system("pause");
			system("cls");
		}
		else if (oper == 4)
		{
			system("cls");
			int input;
			cout << "1. Sort by Name\n";
			cout << "2. Sort by Surname.\n";
			cout << "3. Sort by age.\n";
			cout << "4. Sort by average.\n";
			cin >> input;
			switch (input)
			{
			case 1:
				Group1.Sort(NAME);
				break;
			case 2:
				Group1.Sort(SURNAME);
				break;
			case 3:
				Group1.Sort(AGE);
				break;
			case 4:
				Group1.Sort(AVERAGE);
				break;
			default:
				cout << "Invalid operation number!\n";
				system("pause");
				break;
			}	
		}
		else if (oper == 5)
			Group1.Print();
		else if (oper == 6)
		{
			int stud_num;
			cout << "Input student`s number: ";
			cin >> stud_num;
			Group1.DeleteStudent(stud_num);
			system("pause");
		}

		else if (oper == 7)
			exit(0);
		else
		{
			cout << "Invalid operation number! \n";
			system("pause");
		}		
	}
	system("cls");
}