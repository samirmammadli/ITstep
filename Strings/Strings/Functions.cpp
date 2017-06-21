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

void change_space(char *arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == 32)
		{
			arr[i] = '\t';
		}
	}
}

void print(char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		cout << arr[i];
		i++;
	}
	cout << endl;
}

void find_num(char *arr, int &letter, int &number, int &other)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 48 && arr[i] <= 57)
			number++;
		else if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
			letter++;
		else
			other++;
	}
}

void words_count(char *arr, int &words) // 1 bukvu za slovo ne schitaet
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		while (arr[i] == 45 || (arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
		{
			count++;
			i++;
		}
		count > 1 ? words++ : 0;
		count = 0;
	}
}

void is_palendrom(char *arr, bool &palendrom)
{
	int size = mystrlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - 1 - i])
			palendrom = false;
	}
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
	int index = mystrlen(str2);
	for (int i = 0; str1[i] != '\0'; i++)
	{
		for (int k = i, j = 0; str1[k] == str2[j]; j++, k++)
		{
			if (j == index - 1)
				return &str1[i];
		}
	}
	return 0;
}

int mystrcmp(const char * str1, const char * str2)
{
	int size1 = 0, size2 = 0;
	bool match = true;
	if (mystrlen(str1) == mystrlen(str2))
	{
		for (int i = 0; str1[i] != '\0' && match; i++)
		{
			if (str1[i] != str2[i])
				match = false;
		}
		if (match)
			return 0;
	}
	for (int i = 0; str1[i] != '\0'; i++)
	{
		size1 += str1[i];
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		size2 += str2[i];
	}

	if (size1 > size2)
		return 1;
	else
		return -1;
}

int StringToNumber(char * str)
{
	int digit = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 47 && str[i] < 58)
		{
			if (digit == 0)
				digit = str[i] - 48;
			else
				digit = digit * 10 + (str[i] - 48);
		}
	}
	return digit;
}

char * NumberToString(int number)
{
	
	int temp_numb = 0;
	int size = 0;
	for (int i = 0; number > 0; i++)
	{
		temp_numb *= 10;
		temp_numb += number % 10;
		number /= 10;
		size++;
	}
	char* str = new char[1000];
	for (int i = 0; temp_numb > 0; i++)
	{
		str[i] = (temp_numb % 10) +48;
		temp_numb /= 10;
		if (temp_numb == 0)
			str[size] = '\0';
	}
	return str;
}

char * Uppercase(char * str1)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] > 96 && str1[i] < 123)
		{
			str1[i] -= 32;
		}
	}
	return str1;
}

char * Lowercase(char * str1)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] > 64 && str1[i] < 91)
		{
			str1[i] += 32;
		}
	}
	return str1;
}