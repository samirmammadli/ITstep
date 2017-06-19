#include <iostream>
#include <Windows.h>
using namespace std;

struct lesh
{

};


void main()
{

	char *str = new char[200];
	int size = 9;
	char **arr2 = new char*[size];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = new char[200]{"Salam"};
	}

	printf("%p\n", arr2[0][0]);
	arr2[0] = "Zahid";
	printf("%p\n", arr2[0][0]);
	arr2[1] = "Fatima";
	arr2[2] = "Arif";
	arr2[3] = "Maksim";
	arr2[4] = "Tahir";
	arr2[5] = "Vasif";
	arr2[6] = "Ruslan";
	arr2[7] = "Samir";
	arr2[8] = "Babek";
	
	for (int i = 0; i < size; i++)
	{
		cout << arr2[i] << endl;
	}
	cout << arr2[2] << "\n\n\n";

	for (int i = 0; i < size -1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr2[i][0] > arr2[j][0])
			{
				str = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = str;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr2[i] << endl;
	}
}