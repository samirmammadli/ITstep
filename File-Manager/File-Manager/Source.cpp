#include "FM build.h"



void Renew(FmBuild &fm, bool search = false)
{
	system("cls");
	fm.printFrame();
	fm.print(search);
}

void main()
{ 
	vector<FileInfoCopy> file;
	hideCursor(true);
	system("color 1B");
	int key = 0;
	setlocale(LC_ALL, "Rus");
	char temp[MAX_PATH];

	/*FileManager fm;
	fm.findFolders("C:\\*", "*.txt", file);
	for (int i = 0; i < file.size(); i++)
	{
		cout << file[i].buffer  << file[i].file.name << endl;
	}*/
	FmBuild fm;
	fm.setPatch("C:\\");
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
				fm.setPatch(temp);
				fm.showFolders();
				Renew(fm);
			}
			else if (key == 61)
			{
				fm.search(temp);
				Renew(fm, true);
			}
		}
		else if (key == 13)
		{
			fm.nextFolder();
			Renew(fm);
		}
		else if (key == 27)
			exit(0);
	}
	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());

}
