#pragma once
#include "Printing.h"


class FmBuild {
	FileManager fm;
	Printing Print;
	FileProp *properties;
	vector<_finddata_t> filecpy;
	int textBufferSize = 25;

	void printFrame()
	{
		Print.printTable(79, 27);
		Print.printTable(40, 20, 80, 0);
		Print.printTable(40, 6, 80, 21);
		Print.printText(0, 37, DARKBLUE, YELLOW, " Name ");
		Print.printText(0, 97, DARKBLUE, YELLOW, " Info ");

	}
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
		Print.printText(27, 0, DARKBLUE, YELLOW, "Current Folder:");
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
public:
	void print(string &str)
	{
		system("cls");
		str.pop_back();
		char temp[MAX_PATH];
		printFrame();
		chdir(str.c_str());
		getcwd(temp, MAX_PATH);
		Print.printText(27, 16, DARKBLUE, CYAN, temp);
		int i = 0;
		int cursor = 0;
		int key = -1;
		bool key_pressed = false;
		COORDS(0, 3);
		while (filecpy.size() != 0)
		{
			for (; filecpy.size() != 0; i++)
			{
				if (filecpy[i].attrib & _A_SUBDIR)
					COLORS(WHITE, DARKBLUE);
				else if (filecpy[i].attrib & _A_HIDDEN)
					COLORS(DARKCYAN, DARKBLUE);
				if (i == cursor)
				{
					getAttributes(filecpy[i]);
					printInfo();
					COLORS(BLACK, DARKCYAN);
				}
				COORDS(short(i % textBufferSize + 1), 2);
				cout << filecpy[i].name;
				COLORS(CYAN, DARKBLUE);
				if (i == filecpy.size() - 1 || (i + 1) % textBufferSize == 0) break;
			}
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == 72 && cursor > 0) (cursor--, key_pressed = true);
				else if (key == 80 && cursor < filecpy.size() - 1) (cursor++, key_pressed = true);
				else if (key == 83)
				{
					fm.Remove(str + filecpy[cursor].name);
					return;
				}

			}
			else if (key == 0)
			{
				key = getch();
				if (key == 60)
				{

					0;//Rename(str + filecpy[cursor].file.name);
				}
			}
			if (key == 13 && (filecpy[cursor].attrib & _A_SUBDIR))
			{
				chdir(filecpy[cursor].name);
				system("cls");
				return;
			}

			if (cursor % textBufferSize == 0 && key == 80 || (cursor % textBufferSize == textBufferSize - 1 && key == 72) && cursor != 0)
			{
				system("cls");
				printFrame();
				Print.printText(27, 16, DARKBLUE, CYAN, temp);
			}
			i = cursor - cursor % textBufferSize;
		}
	}
};
