#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	string name;
	Student* next;
	string surname;
	Student(string name = "", string surname = "") {
		this->name = name;
		this->surname = surname;
		next = nullptr;
	}
};

class StudentArray {
	Student* head;
public:
	StudentArray(string name = "", string surname = "") {
		head = new Student;
		head->name = name;
		head->surname = surname;
		head->next = nullptr;
	}
	void addStudent(string name, string surname) {
		Student* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new Student(name, surname);
	}
	void show() {
		Student* tmp = head;
		while (tmp->next != nullptr) {
			cout << tmp->name << " " << tmp->surname << endl;
			tmp = tmp->next;
		}
		cout << tmp->name << " " << tmp->surname << endl;
	}
	int getSize() {
		int count = 0;
		Student* temp = head;
		while (temp->next != nullptr) {
			count++;
			temp = temp->next;
		}
		count++;
		return count;
	}
};


int main()
{

	/*wchar_t p[50];
	wcin.getline(p, 50);
	wprintf (p);*/

	char p[50] = "Привет лошадь";
	//cin.getline(p, 50);
	printf(p); 
	return 0;
}