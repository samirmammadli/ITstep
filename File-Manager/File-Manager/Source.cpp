#include "FM build.h"



void Renew(FmBuild &fm, bool search = false)
{
	system("cls");
	fm.printFrame();
	fm.print(search);
}



void main()
{ 
	hideCursor(true);
	system("color 1B");
	int key = 0;
	setlocale(LC_ALL, "Rus");
	char temp[MAX_PATH];

	FmBuild fm;
	fm.setPath("C:\\users\\samir\\\desktop\\");
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
			if (key == 72 || key == 80) fm.print(true);
		}
		else if (key == 0)
		{
			key = getch();
			if (key == 66)
			{
				fm.changeFolder(temp);
				fm.setPath(temp);
				fm.showFolders();
				Renew(fm);
			}
			else if (key == 60)
			{
				fm.Rename(temp);
				Renew(fm, true);
			}
			else if (key == 61)
			{
				fm.search(temp);
				Renew(fm, true);
			}
			else if (key == 62)
			{
				fm.Copy(true);
				Renew(fm);
			}
			else if (key == 63)
			{
				fm.Paste();
				Renew(fm);
			}
			else if (key == 64)
			{
				fm.Copy();
				Renew(fm);
			}
		}
		else if (key == 13)
		{
			if (fm.nextFolder()) Renew(fm);
		}
		else if (key == 27)
			exit(0);
	}
	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());

}
