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
	return str1;
}

char * mystrcpy(char * str1, const char * str2)
{
	int length = 0;
	for (int i = 0; str2[i] != '\0'; i++)
	{
		str1[i] = str2[i];
		length++;
	}
	str1[length] = '\0';
	return str1;
}

char * mystrchr(char * str, char s)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == s)
			return &str[i];
	}
	return 0;
}

char * mystrstr(char * str1, char * str2)
{

}