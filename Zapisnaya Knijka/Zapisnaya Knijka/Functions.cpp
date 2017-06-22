#include <iostream>
#include <conio.h>
using namespace std;

void disp_list(char **str, int w)
{
	for (int i = 0; i < w && str[i][0] != '\0'; i++)
	{
		cout << i+1 << ". " << str[i] << endl;
	}
}

void add_cont(char **str, int w, int h, int &count)
{
	bool empty_line = false;

	for (int i = 0; i < w && !empty_line; i++)
	{
		if (str[i][0] == '\0')
		{
			cout << "Please, enter Contact Name:\n";
			getchar();
			cin.getline(str[i], h);
			empty_line = true;
			count++;
		}
	}
	disp_list(str, w);
}

void sort_cont(char **str, int w, int h)
{
	char *temp = new char[h];
	for (int i = 0; i < w; i++)
	{
		for (int j = i+1; j < w-1; j++)
		{
			if (str[i][0] > str[j][0])
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
	delete[]temp;
	disp_list(str, w);
}