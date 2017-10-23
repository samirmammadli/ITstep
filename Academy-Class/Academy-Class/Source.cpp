#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#define COORDS(col, row) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)row, (short)col})
#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + fg);
using namespace std;


enum Colors
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	DARKGREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	DEFAULT = 7
};

class Menu {
	int size;
	int index;
public:
	Menu() : size(0), index(0) {}
	void printMenu(short col, short row, vector<string> f)
	{
		size = f.size();
		COORDS(col, row);
		for (short i = 0; i < size; i++)
		{
			if (i == index) COLORS(BLACK, DARKGREY);
			cout << f[i];
			COLORS(DEFAULT, BLACK);
			COORDS(col + i+1, row);
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
		else if (key == 13)
			return index;
		return -1;
	}
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

	//Get data
	virtual string getName() const { return this->name; } 
	virtual string getSurname() const { return this->surname; }
	virtual string getPhone() const { return this->phone; }
	virtual string getEmail() const { return this->email; }
	virtual short getAge() const { return this->age; }

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
	void addStudentToGroup(Student *stud) { students.push_back(stud); }
	void addTeacherToGroup(Teacher *teacher) { this->teacher.push_back(teacher); }
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
	Academy(string name, string city, string address, int fee, int money)
	{
		this->name = name;
		this->city = city;
		this->address = address;
		this->monthlyFee = fee;
		this->money = money;
		stud_id = 0;
		empl_id = 0;
		director = nullptr;
	}
	~Academy() { delete director; } 

	//Set data
	void setName(string name) { this->name = name; }
	void setCity(string city) { this->city = city; }
	void setAddress(string address) { this->address = address; }
	void setFee(int fee) { this->monthlyFee = fee; }
	void setMoney(int money) { this->money = money; }
	void setDirector(const Director &d) 
	{
		this->director = new Director;
		*this->director = d;
	}
	void addStudent(const Student &stud) { students.push_back(stud); }
	void addEmployee(Employee *empl) { employees.push_back(empl); }
	void addGroup(const Group &gr, int group)
	{
		if (group == 1)
			designers.push_back(gr);
		else if (group == 2)
			programmer.push_back(gr);
		else if (group == 3)
			admin.push_back(gr);
	}
	void deleteGroup(int group, int index)
	{
		if (group == 1)
			designers.erase(designers.begin() + index);
		else if (group == 2)
			programmer.erase(programmer.begin() + index);
		else if (group == 3)
			admin.erase(admin.begin() + index);
	}
	void addTeacherToGroup(Teacher* teacher, int group, int index)
	{
		if (group == 1)
			designers[index].addTeacherToGroup(teacher);
		else if (group == 2)
			programmer[index].addTeacherToGroup(teacher);
		else if (group == 3)
			admin[index].addTeacherToGroup(teacher);
	}
	void addStudentToGroup(Student* stud, int group, int index)
	{
		if (group == 1)
			designers[index].addStudentToGroup(stud);
		else if (group == 2)
			programmer[index].addStudentToGroup(stud);
		else if (group == 3)
			admin[index].addStudentToGroup(stud);
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
	const Director* const getDirector() const { return director; }
};




//class Program {
//public:
//	static void load();
//	//	static void save();
//	static void menu();
//};

void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void main()
{

	//Program::menu();

	//Teacher a;
	//Employee *temp = &a;
	//if (typeid(*temp) == typeid(Teacher))
	//{
	//	COORDS(15, 0);
	//	cout << "Alindi\n";
	//	cout << typeid(*temp).name() << endl;
	//}
	//	
	//else
	//	cout << typeid(*temp).name() << endl;
	//	cout << "Alinmadi\n";
	Academy a("IT Step", "Baku", "Z.Aliyeva", 250, 150000);
	Menu m;
	vector<string> s;


	{
		printf("%-20s%s\n", "Academy name:", a.getName().c_str());
		printf("%-20s%s\n", "City:", a.getCity().c_str());
		printf("%-20s%s\n", "Adress:", a.getAdress().c_str());
		printf("%-20s%d Azn\n", "Monthly Fee:", a.getFee());
		printf("%-20s%d Azn\n", "Money:", a.getMoney());
		printf("%-20s%d \n", "Groups:", a.getGroupCount());
		printf("%-20s%d \n", "Students:", a.getStudCount());
		printf("%-20s%d \n", "Employee:", a.getEmployeeCount());
	}
	system("pause");



	s.push_back("Academy Info");
	s.push_back("Show Groups");
	s.push_back("Show Employees");
	s.push_back("Exit");
	hideCursor(true);
	int index;
	while (true)
	{
		m.printMenu(0, 0, s);
		index = m.handling();
		if (index != -1)
		{
			if (index == 0)
			{
				index = -1;
				system("cls");
				while (index == -1)
				{
					COORDS(0, 0);
					vector<string> u;
					u.push_back("back");
					m.printMenu(8, 0, u);
					index = m.handling();
				}
				system("cls");
			}
			else if (index == 3)
				exit(0);
		}
		
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