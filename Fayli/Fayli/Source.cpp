#include <iostream>
#define STRING_SIZE 100
using namespace std;

FILE* list;

int list_size = 0;

void main()
{
	char buffer[STRING_SIZE];
	char patch[_MAX_PATH];
	sprintf(patch, "%s%s", getenv("USERPROFILE"), "\\Desktop\\list.txt");
	list = fopen(patch, "r");
	if (list != NULL)
	{
		list_size = 1;
		while (!feof(list))
		{
			if(fgetc(list) == '\n')
			list_size++;
		}

	}

	
	char ** job_list = new char*[list_size];
	for ( int i = 0; i < list_size; i++)
	{
		job_list[i] = new char[STRING_SIZE];
	}
}