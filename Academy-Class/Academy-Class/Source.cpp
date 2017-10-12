#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
	string name;
	string surname;
	int age;
	string phone;
	string email;
};
class Student : public Person {
	double average;
	double presence;
};
class Employee : public Person {
	int salary;
	int experience;
};
class Teacher : public Employee {
	string skills[];
};
class Salesman : public Employee {
	int contracts;
};
class Director : public Employee {
	double rating;
};

class Academy {
	string name;
	string city;
	string address;
	int monthlyFee;
	int money;
	Director *director;
	vector<Group> designers;
	vector<Group> programmer;
	vector<Group> admin;
	vector<Student> students;
	vector<Employee> employees;
};
class Group {
	string name;
	string subject;
	vector<Student*> students;
	vector<Teacher*> teacher;
};

class Program {
public:
	static void load();
	//	static void save();
	static void menu();
};

void main()
{
	Program::menu();
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