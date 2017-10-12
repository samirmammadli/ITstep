#include "FM build.h"

void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Renew(FmBuild &fm)
{
	system("cls");
	fm.printFrame();
	fm.print();
}

void main()
{ 

	hideCursor(true);
	system("color 1B");
	int key = 0;
	setlocale(LC_ALL, "Rus");
	FmBuild fm;
	fm.setPatch("G:\\");
	fm.showFolders();
	fm.printFrame();
	fm.print();
	while (true)
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 72) fm.setUP();
			else if (key == 80) fm.setDown();
			else if (key == 83)
			{
				fm.deleteFile();
				Renew(fm);
			}
			if (key == 72 || key == 80) fm.print();
		}
		else if (key == 0)
		{
			key == getch();
		}
		else if (key == 13)
		{
			fm.changeFolder();
			Renew(fm);
		}
		
		/*str = getcwd(dir, 255);
		str += "\\*";*/
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