#include <iostream>
#include "Functions.h"
#define SIZE 10
#define STRING_SIZE 100
using namespace std;


void main()
{
	int cont_count = 0;
	int operation;
	char **list = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		list[i] = new char[STRING_SIZE]{};
	}
	strcpy(list[0], "Samir Mammadli");
	strcpy(list[1], "Kamal Jafarov");
	strcpy(list[2], "Ibrahim Aliyev");
	strcpy(list[3], "Rufat Gaibov");

	for (int i = 0; i < SIZE; i++)
	{
		if (list[i][0] != '\0')
			cont_count++;
	}
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

	add_cont(list, SIZE, STRING_SIZE, cont_count);
	cout << endl;
	sort_cont(list, SIZE, STRING_SIZE);
	disp_list(list, SIZE);

}