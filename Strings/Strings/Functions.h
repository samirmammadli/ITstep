#pragma once

int mystrlen(const char * str);
void change_space(char *arr);
void print(char *arr);
void find_num(char *arr, int &letter, int &number, int &other);
void words_count(char *arr, int &words);
void is_palendrom(char *arr, bool &palendrom);



char * mystrcat(char * str1, const char * str2);
char * mystrcpy(char * str1, const char * str2);
char * mystrchr(char * str, char s);
char * mystrstr(char * str1, char * str2);
int mystrcmp(const char * str1, const char * str2);
int StringToNumber(char * str);
char * NumberToString(int number);
char * Uppercase(char * str1);
char * Lowercase(char * str1);