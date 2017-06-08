#include <iostream>
using namespace std;


int mystrlen(const char * str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}

char * mystrcat(char  *str1, const char * str2)
{
	int length = mystrlen(str1);
	for (int i = 0; str2[i] != '\0'; i++, length++)
	{
		str1[length] = str2[i];
	}
	str1[length] = '\0';
	return &str1[0];
}