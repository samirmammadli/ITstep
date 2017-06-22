#include <iostream>
#include "Functions.h"
#define STRING_SIZE 100
using namespace std;


void main()
{
	int SIZE = 4;
	int operation;
	char **list = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		list[i] = new char[STRING_SIZE]{};
	}
	strcpy(list[0], "Damir Mammadli");
	strcpy(list[1], "Camal Jafarov");
	strcpy(list[2], "Bbrahim Aliyev");
	strcpy(list[3], "Aufat Gaibov");

//
	cout << "\t\t\t*****Contact Book.*****\n";
	cout << "Select an action:\n\n";
	cout << "1. Display All Contacts.\n";
	cout << "2. Add new Contact.\n";
	cout << "3. Delete Contact.\n";
	cout << "4. Edit Contact.\n";
	cout << "5. Sort Contacts by Name.\n";
	cout << "6. Search Contact.\n";
	cout << "7. Exit.\n";

	cin >> operation;
	disp_list(list, SIZE);

	add_cont(list, SIZE, STRING_SIZE);
	cout << endl;
	sort_cont(list, SIZE, STRING_SIZE);
	disp_list(list, SIZE);
	cout << endl;
	delete_cont(list, SIZE, STRING_SIZE, 3);
	disp_list(list, SIZE);
	cout << endl;

}