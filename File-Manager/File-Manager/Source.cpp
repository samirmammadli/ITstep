#include "FM build.h"

void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}



void main()
{ 

	hideCursor(true);
	system("color 1B");


	char dir[MAX_PATH];
	getcwd(dir, 255);
	setlocale(LC_ALL, "Rus");
	string str = dir;
	str += "\\*";
	system("cls");
	str = "C:";
	FmBuild fm;
	while (true)
	{
		fm.print(str);
		str = getcwd(dir, 255);
		str += "\\*";
	}
	/*fm.showDirectory(str);
	fm.print();*/
	//fm.findFolders("C:\\*", "*.??");





	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());
	

}


//#include <stdio.h>
//#include <direct.h>
//#include <iostream>
//int main(void)
//{
//	char dir[255];
//	getcwd(dir, 255);
//	printf("Current directory is %s\n", dir);
//	strcpy(dir, "C:\\Users\\Samir\\Source\\Repos\\ITstep\\..\\");
//	chdir(dir);
//	getcwd(dir, 255);
//	printf("Current directory is %s\n", dir);
//	return 0;
//}