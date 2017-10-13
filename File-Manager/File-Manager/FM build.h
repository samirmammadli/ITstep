#pragma once
#include "FM.h"


class FmBuild {
	FileManager fm;
	Printing Print;
	FileProp *properties;
	vector<FileInfoCopy> filecpy;
	string patch;
	int textBufferSize = 25;
	int i = 0;
	int cursor = 0;
	char temp[MAX_PATH];
	void printInfo()
	{
		Print.printText(2, 82, DARKBLUE, YELLOW, "Type:");
		Print.printText(2, 87, DARKBLUE, CYAN, properties->type);
		Print.printText(4, 82, DARKBLUE, YELLOW, "Attributes:");
		Print.printText(4, 93, DARKBLUE, CYAN, properties->attr);
		Print.printText(6, 82, DARKBLUE, YELLOW, "Size:");
		Print.printText(6, 87, DARKBLUE, CYAN, properties->size_type);
		Print.printText(14, 82, DARKBLUE, YELLOW, "Created:");
		Print.printText(14, 90, DARKBLUE, CYAN, properties->time_c);
		Print.printText(16, 82, DARKBLUE, YELLOW, "Changed:");
		Print.printText(16, 90, DARKBLUE, CYAN, properties->time_w);
		Print.printText(18, 82, DARKBLUE, YELLOW, "Access:");
		Print.printText(18, 89, DARKBLUE, CYAN, properties->time_a);
		Print.printText(27, 0, DARKBLUE, YELLOW, "Folder:");
	}
	bool removeWarning()
	{
		COLORS(WHITE, DARKRED);
		Print.printTable(40, 6, 80, 21);
		Print.printText(21, 92, DARKRED, WHITE, " Data Removal ");
		Print.printText(22, 81, DARKRED, WHITE, "                                      ");
		Print.printText(23, 81, DARKRED, WHITE, "    Do you want to remove");
		if (filecpy[cursor].file.attrib & _A_SUBDIR)
			Print.printText(23, 106, DARKRED, WHITE, " folder ?    ");
		else
			Print.printText(23, 106, DARKRED, WHITE, " file ?      ");
		Print.printText(24, 81, DARKRED, WHITE, "                 Y/N ?                ");
		Print.printText(25, 81, DARKRED, WHITE, "                                      ");
		char Key = _getch();
		if (Key == 'y') return true;
		else return false;
	}
	void pathField()
	{
		COLORS(WHITE, DARKRED);
		Print.printTable(100, 3, 10, 10);
		Print.printText(10, 49, DARKRED, WHITE, " Input new patch: ");
		Print.printText(11, 11, DARKRED, WHITE, "                                                                                                  ");
	}
	void searchField()
	{
		COLORS(WHITE, DARKRED);
		Print.printTable(100, 3, 10, 10);
		Print.printText(10, 53, DARKRED, WHITE, " Input name: ");
		Print.printText(11, 11, DARKRED, WHITE, "                                                                                                  ");
	}
	void renField()
	{
		COLORS(WHITE, DARKRED);
		Print.printTable(100, 3, 10, 10);
		Print.printText(10, 50, DARKRED, WHITE, " Input new name: ");
		Print.printText(11, 11, DARKRED, WHITE, "                                                                                                  ");
	}
	void getAttributes(const _finddata_t &file)
	{
		char temp[500];
		properties->size = file.size;
		properties->size_type = "B";

		if (properties->size >= 1000)
		{
			properties->size /= 1000;
			properties->size_type = "Kb";
		}
		if (properties->size >= 1000)
		{
			properties->size /= 1000;
			properties->size_type = "Mb";
		}
		if (properties->size >= 1000)
		{
			properties->size /= 1000;
			properties->size_type = "Gb";
		}
		file.attrib & _A_SUBDIR ? properties->type = "Folder" : properties->type = "File";
		properties->attr = "";
		if (file.attrib & _A_RDONLY)  properties->attr += " R ";
		if (file.attrib & _A_HIDDEN)  properties->attr += " H ";
		if (file.attrib & _A_SYSTEM)  properties->attr += " S";
		if (properties->attr.size() == 0) properties->attr = " Normal";

		sprintf(temp, "%31s", properties->type.c_str());
		properties->type = temp;

		sprintf(temp, "%25s", properties->attr.c_str());
		properties->attr = temp;


		char tmp[100];
		sprintf(tmp, "%.3g %s", properties->size, properties->size_type.c_str());
		sprintf(temp, "%31s", tmp);
		properties->size_type = temp;

		strftime(tmp, 20, "%d-%m-%Y %H:%M:%S", localtime(&file.time_create));
		sprintf(temp, "%27s", tmp);
		properties->time_c = temp;

		strftime(tmp, 20, "%d-%m-%Y %H:%M:%S", localtime(&file.time_access));
		sprintf(temp, "%28s", tmp);
		properties->time_a = temp;

		strftime(tmp, 20, "%d-%m-%Y %H:%M:%S", localtime(&file.time_write));
		sprintf(temp, "%27s", tmp);
		properties->time_w = temp;

	}
	void checkScrolling(bool direction)
	{
		if (cursor % textBufferSize == 0 && direction || (cursor % textBufferSize == textBufferSize - 1 && !direction) && cursor != 0)
		{
			system("cls");
			printFrame();
		}
		i = cursor - cursor % textBufferSize;
	}
public:
	~FmBuild()
	{
		delete properties;
	}
	FmBuild() : i(0), cursor(0), patch("\\*")
	{
		properties = new FileProp;
	}
	void printFrame()
	{
		Print.printTable(79, 27);
		Print.printTable(40, 20, 80, 0);
		Print.printTable(40, 6, 80, 21);
		Print.printText(0, 37, DARKBLUE, YELLOW, " Name ");
		Print.printText(0, 97, DARKBLUE, YELLOW, " Info ");
		Print.printText(28, 0, BLACK, WHITE, "F2");
		Print.printText(28, 2, DARKCYAN, BLACK, "Rename");
		Print.printText(28, 15, BLACK, WHITE, "Del");
		Print.printText(28, 18, DARKCYAN, BLACK, "Delete");
		Print.printText(28, 31, BLACK, WHITE, "F3");
		Print.printText(28, 33, DARKCYAN, BLACK, "Search");
		Print.printText(28, 44, BLACK, WHITE, "F4");
		Print.printText(28, 46, DARKCYAN, BLACK, "Cut");
		Print.printText(28, 56, BLACK, WHITE, "F5");
		Print.printText(28, 58, DARKCYAN, BLACK, "Paste");
		Print.printText(28, 70, BLACK, WHITE, "ESC");
		Print.printText(28, 73, DARKCYAN, BLACK, "EXIT");
	}
	void search(char * Temp)
	{
		i = 0;
		cursor = 0;
		filecpy.clear();
		searchField();
		COORDS(11, 11);
		COLORS(WHITE, DARKRED);
		hideCursor(false);
		cin.getline(Temp, MAX_PATH);
		hideCursor(true);
		fm.findFolders(patch, Temp, filecpy);
		COLORS(CYAN, DARKBLUE);
	}
	void setUP()
	{
		if (cursor > 0)
		{
			cursor--;
			checkScrolling(false);
		}
	}
	void Rename(char *Temp)
	{
		renField();
		COORDS(11, 11);
		COLORS(WHITE, DARKRED);
		hideCursor(false);
		cin.getline(Temp, MAX_PATH);
		hideCursor(true);
		renField();
		if (filecpy.size() > 0 )
			fm.Rename(filecpy[cursor].buffer + filecpy[cursor].file.name, Temp);
		showFolders();
		COLORS(CYAN, DARKBLUE);
	}
	void setDown()
	{
		if (cursor < filecpy.size() - 1)
		{
			cursor++;
			checkScrolling(true);
		}
	}
	void showFolders()
	{
		i = 0;
		cursor = 0;
		filecpy.clear();
		fm.showDirectory(patch, filecpy);
	}
	void setPath(string tmp_patch = "\\*")
	{
		chdir(tmp_patch.c_str());
		getcwd(temp, MAX_PATH);
		patch = temp;
		patch += "\\*";
	}
	void deleteFile()
	{
		if (filecpy.size() > 0)
		{
			if (!(filecpy[cursor].file.attrib & _A_SUBDIR))
			{
				if (removeWarning())
					fm.Remove(filecpy[cursor].buffer + filecpy[cursor].file.name);
			}
			else
			{
				if (removeWarning())
					fm.Remove(filecpy[cursor].buffer + filecpy[cursor].file.name, true);
			}
		}
		showFolders();
	}
	void changeFolder(char *Temp)
	{
		pathField();
		COORDS(11, 11);
		COLORS(WHITE, DARKRED);
		hideCursor(false);
		cin.getline(Temp, MAX_PATH);
		hideCursor(true);
		COLORS(CYAN, DARKBLUE);
	}
	bool nextFolder()
	{
		if (filecpy.size() == 0)
		{
			setPath("..");
			showFolders();
			return true;
		}
		else if (filecpy[cursor].file.attrib & _A_SUBDIR)
		{
			setPath(filecpy[cursor].file.name);
			showFolders();
			return true;
		}
		else
			return false;
		
	}
	void print(bool search = false)
	{
		printInfo();
		COORDS(0, 3);
		if (filecpy.size() != 0)
		{
			for (; i < filecpy.size(); i++)
			{
				if (filecpy[i].file.attrib & _A_SUBDIR)
					COLORS(WHITE, DARKBLUE);
				else if (filecpy[i].file.attrib & _A_HIDDEN)
					COLORS(DARKCYAN, DARKBLUE);
				if (i == cursor)
				{
					getAttributes(filecpy[i].file);
					printInfo();
					Print.printText(27, 8, DARKBLUE, CYAN, "                                                                                                                ");
					Print.printText(27, 8, DARKBLUE, CYAN, filecpy[i].buffer);
					COLORS(BLACK, DARKCYAN);
				}
				COORDS(short(i % textBufferSize + 1), 2);
				printf("%.75s", filecpy[i].file.name);
				COLORS(CYAN, DARKBLUE);
				if (i == filecpy.size() - 1 || (i + 1) % textBufferSize == 0) break;
			}
		}
	}
};
