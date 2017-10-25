#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#define COORDS(col, row) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + fg);
using namespace std;


void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

enum Colors
{
	BLACK,
	DARKGREY = 8,
	DEFAULT = 7
};

enum GroupName {
	DESIGNERS,
	PROGRAMMERS,
	ADMIN
};


class SelectableMenuLines
{
public:
	vector<string> add_del_edit;
	vector<string> person_edit;
	vector<string> main_menu;
	vector<string> edit_acad;
	vector<string> group_management;
	vector<string> group_mgt_edit;
	vector<string> stud_mgt_edit;
	vector<string> employee_management;
	vector<string> employee_submenu;
	vector<string> director_mgt_edit;
	vector<string> teacher_mgt_edit;
	vector<string> salesman_mgt_edit;

	SelectableMenuLines()
	{
		add_del_edit.push_back("Add");
		add_del_edit.push_back("Delete");
		add_del_edit.push_back("Edit");

		person_edit.push_back("Change Name");
		person_edit.push_back("Change Surname");
		person_edit.push_back("Change Mail");
		person_edit.push_back("Change Phone");
		person_edit.push_back("Change age");

		main_menu.push_back("Academy general information");
		main_menu.push_back("List of Groups");
		main_menu.push_back("List of Students");
		main_menu.push_back("List of Personnel");
		main_menu.push_back("Edit academy");
		main_menu.push_back("Group management");
		main_menu.push_back("Student management");
		main_menu.push_back("Employee management");
		main_menu.push_back("Raise salary");
		main_menu.push_back("Lower salary");
		main_menu.push_back("Exit");

		edit_acad.push_back("Change name");
		edit_acad.push_back("Change city");
		edit_acad.push_back("Change address");
		edit_acad.push_back("Change monthly fee");
		edit_acad.push_back("Change budget");

		group_management.push_back("Programmers");
		group_management.push_back("Designers");
		group_management.push_back("Admins");

		group_mgt_edit.push_back("Change Name");
		group_mgt_edit.push_back("Change Subject");
		group_mgt_edit.push_back("Add Student");
		group_mgt_edit.push_back("Delete Student");
		group_mgt_edit.push_back("Add Teacher");
		group_mgt_edit.push_back("Delete Teacher");

		stud_mgt_edit = person_edit;
		stud_mgt_edit.push_back("Change Average");
		stud_mgt_edit.push_back("Change Presence");

		employee_management.push_back("Director");
		employee_management.push_back("Teacher");
		employee_management.push_back("Salesman");

		director_mgt_edit = person_edit;
		director_mgt_edit.push_back("Change Rating");

		teacher_mgt_edit = person_edit;
		teacher_mgt_edit.push_back("Change Skills");

		salesman_mgt_edit = person_edit;
		salesman_mgt_edit.push_back("Change Contracts");
	}
	friend class AcademyMenuAssembling;
};



class Control {
public:
	int size;
	int index;
	Control() : size(0), index(0) {}
	void printMenu(vector<string> f, short col = 0, short row = 0)
	{
		size = f.size();
		COORDS(col, row);
		for (short i = 0; i < size; i++)
		{
			if (i == index) COLORS(BLACK, DARKGREY);
			cout << f[i];
			COLORS(DEFAULT, BLACK);
			COORDS(col + i + 1, row);
		}
	}
	int handling()
	{
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 72) index > 0 ? index-- : 0;
			else if (key == 80) index < size - 1 ? index++ : 0;
		}
		else if (key == 27) { index = 0; return -2; }
		else if (key == 13) { int tmp = index; index = 0; return tmp; }
		return -1;
	}
	int Scrolling(vector<string> f, short col = 0, short row = 0)
	{
		system("cls");
		int value = -1;
		while (value == -1)
		{
			printMenu(f, col, row);
			value =	handling();
		}
		return value;
	}
	
	friend class AcademyMenuAssembling;
};


class Person {
protected:
	string name;
	string surname;
	string phone;
	string email;
	short age;
	int personal_id;
public:
	Person() : name("Empty"), surname("Empty"), phone("Empty"), email("Empty"), age(0), personal_id(0) {}
	virtual ~Person() = 0 {}
	//Set data
	virtual void setName(string name) { this->name = name; }
	virtual void setSurname(string surname) { this->surname = surname; }
	virtual void setPhone(string phone) { this->phone = phone; }
	virtual void setEmail(string email) { this->email = email; }
	virtual void setAge(short age) { this->age = age; }
	virtual void setID(int id) { personal_id = id; }

	//Get data
	virtual string getName() const { return this->name; } 
	virtual string getSurname() const { return this->surname; }
	virtual string getPhone() const { return this->phone; }
	virtual string getEmail() const { return this->email; }
	virtual short getAge() const { return this->age; }
	virtual int getID() const { return this->personal_id; }

};


class Student : public Person {
	double average;
	double presence;
public:
	Student() : Person(), average(0), presence(0) {}
	//Set data
	void setAverage(double average) { this->average = average; }
	void setPresence(double presence) { this->presence = presence; }

	//Get data
	double getAverage() const { return this->average; }
	double getPresence() const { return this->presence; }
};


class Employee : public Person {
protected:
	int salary;
	int experience;
public:
	virtual ~Employee() = 0 {}
	Employee() : Person(), salary(0), experience(0) {}
	//Set data
	virtual void setSalary(int salary) { this->salary = salary; }
	virtual void setExperience(int experience) { this->salary = experience; }

	//Get data
	virtual int getSalary() const { return this->salary; }
	virtual int getExperience() const { return this->experience; }
};


class Teacher : public Employee {
	vector<string> skills;
public:
	Teacher() : Employee() {}
	//Set data
	void addSkill(string skill) { skills.push_back(skill); }
	//Get data
	vector<string> getSkills() const { return this->skills; }
};


class Salesman : public Employee {
	int contracts;
public:
	Salesman() : Employee(), contracts(0) {}
	//Set data
	void setContracts(int contracts) { this->contracts = contracts; }
	//Get data
	int getContracts() const { return this->contracts; }
};


class Director : public Employee {
	double rating;
public:
	Director() : Employee(), rating(0) {}
	//Set data
	void setRating(double contracts) { this->rating = contracts; }
	//Get data
	double getRating() const { return this->rating; }
};


class Group {
	string name;
	string subject;
	vector<Student*> students;
	vector<Teacher*> teacher;
public:
	Group() : name("Empty"), subject("Empty") {}
	//Set data
	void setName(string name) { this->name = name; }
	void setSubject(string subject) { this->subject = subject; }
	void addStudent(Student *stud) { students.push_back(stud); }
	void addTeacher(Teacher *teacher) { this->teacher.push_back(teacher); }
	void deleteStudent(int index) { students.erase(students.begin() + index); }
	void deleteTeacher(int index) { teacher.erase(teacher.begin() + index); }
	//Get data
	vector<Student*> getStudents() const { return students; }
	vector<Teacher*> getTeacher() const { return teacher; }
};


class Academy {
	string name;
	string city;
	string address;
	Director *director;
	vector<Group> designers;
	vector<Group> programmer;
	vector<Group> admin;
	vector<Student> students;
	vector<Employee*> employees;
	int monthlyFee;
	int money;
	int stud_id;
	int empl_id;
public:
	Academy(string name, string city, string address, const Director &drct, int fee, int money)
	{
		this->name = name;
		this->city = city;
		this->address = address;
		this->monthlyFee = fee;
		this->money = money;
		stud_id = 0;
		empl_id = 0;
		director = new Director{drct};
	}
	~Academy() { delete director; } 

	//Set data
	void setName(string name) { this->name = name; }
	void setCity(string city) { this->city = city; }
	void setAddress(string address) { this->address = address; }
	void setFee(int fee) { this->monthlyFee = fee; }
	void setMoney(int money) { this->money = money; }
	void raiseSalary(int percent)
	{
		for (int i = 0; i < employees.size(); i++)
		{
			int salary = employees[i]->getSalary();
			salary += salary / 100 * percent;
			employees[i]->setSalary(salary);
		}
	}
	void lowerSalary(int percent)
	{
		for (int i = 0; i < employees.size(); i++)
		{
			int salary = employees[i]->getSalary();
			salary -= salary / 100 * percent;
			employees[i]->setSalary(salary);
		}
	}
	void setDirector(const Director &d) 
	{
		this->director = new Director{ d };
	}
	void addStudent(const Student &stud) 
	{
		students.push_back(stud);
		students[students.size() - 1].setID(++stud_id);
	}
	void addTeacher(const Teacher &teach)
	{
		Teacher *temp = new Teacher{teach};
		employees.push_back(temp);
		employees[employees.size() - 1]->setID(++empl_id);
	}
	void addSalesman(const Salesman &sale)
	{
		Salesman *temp = new Salesman{ sale };
		employees.push_back(temp);
		employees[employees.size() - 1]->setID(++empl_id);
	}
	void addEmployee(Employee *new_empl)
	{
		if (typeid(*new_empl) == typeid(Teacher))
		{
			Teacher *temp = new Teacher{ *dynamic_cast<Teacher*>(new_empl) };
			employees.push_back(temp);
		}
		else if (typeid(*new_empl) == typeid(Salesman))
		{
			Salesman *temp = new Salesman{ *dynamic_cast<Salesman*>(new_empl) };
			employees.push_back(temp);
		}
		employees[employees.size() - 1]->setID(++empl_id);
	}
	void deleteEmployee(int index)
	{
		employees.erase(employees.begin() + index);
	}
	void addGroup(const Group &new_group, GroupName which_group)
	{
		if (which_group == DESIGNERS)
			designers.push_back(new_group);
		else if (which_group == PROGRAMMERS)
			programmer.push_back(new_group);
		else if (which_group == ADMIN)
			admin.push_back(new_group);
	}
	void deleteGroup(GroupName which_group, int index)
	{
		if (which_group == DESIGNERS)
			designers.erase(designers.begin() + index);
		else if (which_group == PROGRAMMERS)
			programmer.erase(programmer.begin() + index);
		else if (which_group == ADMIN)
			admin.erase(admin.begin() + index);
	}
	void addTeacherToGroup(Teacher* new_teacher, GroupName which_group, int index)
	{
		if (which_group == DESIGNERS)
			designers[index].addTeacher(new_teacher);
		else if (which_group == PROGRAMMERS)
			programmer[index].addTeacher(new_teacher);
		else if (which_group == ADMIN)
			admin[index].addTeacher(new_teacher);
	}
	void deleteTeacherFromGroup(GroupName which_group, int index)
	{
		if (which_group == DESIGNERS)
			designers[index].deleteTeacher(index);
		else if (which_group == PROGRAMMERS)
			programmer[index].deleteTeacher(index);
		else if (which_group == ADMIN)
			admin[index].deleteTeacher(index);
	}
	void addStudentToGroup(Student* new_stud, GroupName which_group, int index)
	{
		if (which_group == DESIGNERS)
			designers[index].addStudent(new_stud);
		else if (which_group == PROGRAMMERS)
			programmer[index].addStudent(new_stud);
		else if (which_group == ADMIN)
			admin[index].addStudent(new_stud);
	}
	void deleteStudentFromGroup(GroupName which_group, int index)
	{
		if (which_group == DESIGNERS)
			designers[index].deleteStudent(index);
		else if (which_group == PROGRAMMERS)
			programmer[index].deleteStudent(index);
		else if (which_group == ADMIN)
			admin[index].deleteStudent(index);
	}

	//Get data
	string getName() const { return name; }
	string getCity() const { return city; }
	string getAdress() const { return address; }
	int getFee() const { return monthlyFee; }
	int getMoney() const { return money; }
	int getGroupCount() const { return admin.size() + programmer.size() + designers.size(); }
	int getStudCount() const { return students.size(); }
	int getEmployeeCount() const { return employees.size(); }
	vector<Group> getDesigners() const { return designers; }
	vector<Group> getProgrammers() const { return programmer; }
	vector<Group> getAdmin() const { return admin; }
	vector<Employee*> getEmployees() const { return employees; }
	const Director* const getDirector() const { return director; }
};

class AcademyMenuAssembling
{
	SelectableMenuLines Lines;
	Control control;
public:
	void showAcadInfo(const Academy &a)
	{
		system("cls");
		printf("%-20s%s\n", "Academy name:", a.getName().c_str());
		printf("%-20s%s\n", "City:", a.getCity().c_str());
		printf("%-20s%s\n", "Adress:", a.getAdress().c_str());
		printf("%-20s%d Azn\n", "Monthly Fee:", a.getFee());
		printf("%-20s%d Azn\n", "Money:", a.getMoney());
		printf("%-20s%d \n", "Groups:", a.getGroupCount());
		printf("%-20s%d \n", "Students:", a.getStudCount());
		printf("%-20s%d \n", "Employee:", a.getEmployeeCount());
		system("pause");
	}
	void lowerSalary(Academy &a)
	{
		system("cls");
		int percent;
		cout << "\t\tLower Salary for All Employees:\n";
		cout << "Enter percent: ";
		hideCursor(false);
		cin >> percent;
		hideCursor(true);
		cout << "Salary is lowered for " << percent << "\%" << " percent!\n";
		a.lowerSalary(percent);
		system("pause");
	}
	void raiseSalary(Academy &a)
	{
		system("cls");
		int percent;
		cout << "\t\tRaise Salary for All Employees:\n";
		cout << "Enter percent: ";
		hideCursor(false);
		cin >> percent;
		hideCursor(true);
		cout << "Salary is raised for " << percent << "\%" << " percent!\n";
		a.raiseSalary(percent);
		system("pause");
	}
	void editAcadName(Academy &a)
	{
		system("cls");
		string name;
		cout << "\t\tChange Academy Name\n";
		cout << "Input new name: ";
		hideCursor(false);
		getline(cin, name);
		hideCursor(true);
		cout << "Academy name changed to: " << name << endl;
		a.setName(name);
		system("pause");
	}
};


//class Program {
//public:
//	static void load();
//	//	static void save();
//	static void menu();
//};



void test(Academy &a)
{
	Teacher tech;
	tech.addSkill("Kru");
	tech.addSkill("Tiz");
	tech.addSkill("Na");
	tech.addSkill("Vnature");
	a.addEmployee(&tech);
	Salesman salik;
	salik.setName("samir");
	a.addEmployee(&salik);
}


void main()
{
	Director x;
	Academy a("IT Step", "Baku", "Z.Aliyeva", x, 250, 150000);
	Student stud;
	stud.setAge(18);
	stud.setName("Samir");
	stud.setSurname("Mammadli");
	stud.setAverage(25);
	stud.setEmail("admin@bcdtravel.az");
	a.addStudent(stud);
	test(a);
	
	AcademyMenuAssembling bringinfo;
	Control m;
	SelectableMenuLines MenuLines;

	hideCursor(true);
	int index = -1;
	while (true)
	{
		if (index == -1) index = m.Scrolling(MenuLines.main_menu);
		if (index == 0)
		{
			bringinfo.showAcadInfo(a);
			index = -1;
		}
		else if (index == 1)
		{
			index = m.Scrolling(MenuLines.group_management);
			index = -1;
		}
		else if (index == 4)
		{
			index = m.Scrolling(MenuLines.edit_acad);
			if (index == 0)
			{
				bringinfo.editAcadName(a);
				index = 4;
			}
			else
				index = -1;
		}
		else if (index == 8)
		{
			bringinfo.raiseSalary(a);
			index = -1;
		}
		else if (index == 9)
		{
			bringinfo.lowerSalary(a);
			index = -1;
		}
		else if (index == 10 || index == -2)
			exit(0);
	}
}

/*
---ИНФОРМАЦИЯ---

1. Информация об академии
- Название
- Город
- Адрес
- Количество групп
- Количество студентов
- Количество работников
- Инфо о директоре

2. Вывести список групп (дизайнеры / программисты / админы на выбор)

3. Вывести информацию о группе (поиск по названию)
- Название
- Текущий предмет
- Количество студентов
- Преподаватель
- Средний балл по группе
- Средняя посещаемость по группе

4. Вывести информацию о студентах в группе (поиск по названию)
- Фамилия
- Имя
- Возраст
- Средний балл
- Процент посещаемости
- Телефон
- Email

5. Вывести список сотрудников
- Фамилия
- Имя
- Возраст
- Зарплата
- Стаж (в днях)
- Список навыков (у преподавателей)
- Количество контрактов (у консультантов)
- Рейтинг (у директора)
- Телефон
- Email

6. Рейтинг студентов академии
- Студент с лучшей посещаемостью
- Студент с лучшей успеваемостью
- Группа с лучшей посещаемостью
- Группа с лучшей успеваемостью

7. Рейтинг сотрудников академии
- Сотрудник с самой высокой зарплатой
- Сотрудник с самым большим стажем
- Преподаватель с наибольшим количеством групп

---РЕДАКТИРОВАНИЕ---

1. Студенты
- Добавить студента
- Редактировать студента
- Удалить студента

2. Сотрудники
- Добавить сотрудника
- Редактировать сотрудника
- Удалить сотрудника

3. Группы
- Добавить группу
- Редактировать группу
- Удалить группу

---УПРАВЛЕНИЕ---

1. Показать доходы и расходы академии
- За месяц
- За семестр
- За год

2. Изменить стоимость обучения в академии

3. Повысить / понизить зарплату всем сотрудниками на n%

4. Сменить директора академии

---ВЫХОД---
*/