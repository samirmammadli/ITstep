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
		Print.printText(28, 33, DARKCYAN, BLACK, "Copy");
		Print.printText(28, 44, BLACK, WHITE, "F4");
		Print.printText(28, 46, DARKCYAN, BLACK, "Cut");
		Print.printText(28, 56, BLACK, WHITE, "F5");
		Print.printText(28, 58, DARKCYAN, BLACK, "Paste");
		Print.printText(28, 70, BLACK, WHITE, "ESC");
		Print.printText(28, 73, DARKCYAN, BLACK, "EXIT");
	}
	void setUP()
	{
		if (cursor > 0)
		{
			cursor--;
			checkScrolling(false);
		}
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
	void getPatch()
	{
		patch.pop_back();
		chdir(patch.c_str());
		getcwd(temp, MAX_PATH);
	}
	void changeFolder()
	{
		chdir(filecpy[cursor].file.name);

	}
	void print(bool search = false)
	{
		if (!search) Print.printText(27, 8, DARKBLUE, CYAN, temp);
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
					//if (search) Print.printText(27, 8, DARKBLUE, CYAN, filecpy[i].buffer);
					COLORS(BLACK, DARKCYAN);
				}
				COORDS(short(i % textBufferSize + 1), 2);
				cout << filecpy[i].file.name;
				COLORS(CYAN, DARKBLUE);
				if (i == filecpy.size() - 1 || (i + 1) % textBufferSize == 0) break;
			}
		}
	}
};
