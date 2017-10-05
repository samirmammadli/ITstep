#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <Windows.h>
#include <windows.h>
#include <conio.h>
#define COORDS(col, row) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})

#define COLORS(fg, bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg * 16 + fg)
#define findclose _findclose
using namespace std;

enum Colors
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	DARKGREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	DEFAULT = 7
};



class mainFrame {
	enum Sides {
		VERTICAL, HORIZONTAL, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT
	};
	 unsigned char* symbols;
	
public:
	
	mainFrame()
	{
		symbols = new unsigned char[6];
		symbols[VERTICAL] = 186;
		symbols[HORIZONTAL] = 205;
		symbols[UPLEFT] = 201;
		symbols[UPRIGHT] = 187;
		symbols[DOWNLEFT] = 200;
		symbols[DOWNRIGHT] = 188;
	}
	void  printTable(int width = 0, int height = 0, int indentW = 0, int indentH = 0)
	{
		for (int i = indentH; i < height + indentH; i++)
		{
			for (int j = indentW; j < width + indentW; j++)
			{
				if (i == indentH && j == indentW)
				{
					COORDS(i, j);
						cout << symbols[UPLEFT];
				}
				else if (i == indentH && j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[UPRIGHT];
				}
				else if (i == indentH + height - 1 && j == indentW)
				{
					COORDS(i, j);
						cout << symbols[DOWNLEFT];
				}
				else if (i == indentH + height - 1 && j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[DOWNRIGHT];
				}
				else if (j == indentW)
				{
					COORDS(i, j);
						cout << symbols[VERTICAL];
				}
				else if (j == indentW + width - 1)
				{
					COORDS(i, j);
						cout << symbols[VERTICAL];
				}
				else if (i == indentH)
				{
					COORDS(i, j);
						cout << symbols[HORIZONTAL];
				}
				else if (i == indentH + height - 1)
				{
					COORDS(i, j);
						cout << symbols[HORIZONTAL];
				}

			}
		}
	}
	void printOptions(int _width, int _height)
	{

	}
	
};

struct FileProp
{
	string type;
	string attr = "";
	string size_type = "Bytes";
	double size;
};

struct FileInfoCopy
{
	string buffer;
	_finddata_t file;
};

class FileManager
{
	mainFrame a;
	int textBufferSize = 25;
	vector<FileInfoCopy> filecpy;
	string path;
	FileProp properties;
	void getAttributes(const _finddata_t &file)
	{
		properties.size = file.size;
		properties.size_type = "B";

		if (properties.size >= 1000)
		{
			properties.size /= 1000;
			properties.size_type = "Kb";
		}
		if (properties.size >= 1000)
		{
			properties.size /= 1000;
			properties.size_type = "Mb";
		}
		if (properties.size >= 1000)
		{
			properties.size /= 1000;
			properties.size_type = "Gb";
		}
		file.attrib & _A_SUBDIR ? properties.type = "Folder" : properties.type = "File";
		properties.attr = "";
		if (file.attrib & _A_RDONLY)  properties.attr += " R ";
		if (file.attrib & _A_HIDDEN)  properties.attr += " H ";
		if (file.attrib & _A_SYSTEM)  properties.attr += " S" ;
		if (properties.attr.size() == 0) properties.attr = " Normal";
	}
public:
	FileManager(string path = "C:\*")
	{
		this->path = path;
	}

	void showDirectory(string str)
	{
		_finddata_t fileinfo;
		int handle = _findfirst(str.c_str(), &fileinfo);
		int find = -1;
		if (handle != -1) find = _findnext(handle, &fileinfo);
		int count = 0;
		
		while (find != -1)
		{
			FileInfoCopy temp;
			char buffer[500];
			getAttributes(fileinfo);
			//sprintf(buffer, "%-45.34s%-4s%-9s| %-7.3g|%-3s|\n", fileinfo.name, properties.type.c_str(), properties.attr.c_str(), properties.size, properties.size_type.c_str());
			sprintf(buffer, "%-76.70s", fileinfo.name);
			temp.buffer = buffer;
			temp.file = fileinfo;
			filecpy.push_back(temp);
			find = _findnext(handle, &fileinfo);
			count++;
		}
		findclose(handle);
	}
	void print()
	{
	
		a.printTable(79, 27);
		a.printTable(40, 20, 80, 0);
		a.printTable(40, 6, 80, 21);
		a.printTable(120, 2, 0, 27);
		//a.printTable(0, 0, )
		bool stop = false;
		int i = 0;
		int cursor = 0;
		COORDS( 0, 3 );
		while (!stop && filecpy.size() > 0)
		{
			if (i == cursor) COLORS(BLACK, DARKCYAN);

			COORDS(short(i % textBufferSize +1) , 2);
			cout << filecpy[i].buffer;
			COLORS(CYAN, DARKBLUE);
			i++;
			if (i == filecpy.size() - 1 || i % textBufferSize == 0) stop = control(i, cursor);
		}
		
	}
	bool control(int &i, int &index)
	{
		int key = 0;
		bool key_pressed = false;
		while (!key_pressed)
		{
			key = _getch();
			if (key == 'w' && index > 0) (index--, key_pressed = true);
			else if (key == 's' && index < filecpy.size() - 2) (index++, key_pressed = true);
			else if (key == 13)
			{
				return true;
			}
			
		}
		if (index % textBufferSize == 0 && index !=0)
		{
			system("cls");
			a.printTable(79, 27);
			a.printTable(40, 20, 80, 0);
			a.printTable(40, 6, 80, 21);
			a.printTable(120, 2, 0, 27);
		}
		i = index - index % textBufferSize;
		return false;

	}
	int findFiles(string mask, string patch)
	{
		int count = 0;
		_finddata_t fileinfo;
		int handle = _findfirst(mask.c_str(), &fileinfo);
		int find = -1;
		if (handle != -1) find = _findnext(handle, &fileinfo);
		if (handle != -1) find = _findnext(handle, &fileinfo);
		if (find != -1)
		{
			patch.pop_back();
			string name = fileinfo.name;
			cout << patch + name << endl;
			count++;
		}
		findclose(handle);
		return count;
	}
	void findFolders(string mask, string word)
	{
		_finddata_t fileinfo;
		int handle = _findfirst(mask.c_str(), &fileinfo);
		int find = -1;
		if (handle != -1) find = _findnext(handle, &fileinfo);
		string temp = mask;
		temp.pop_back();
		temp += word;
		findFiles(temp, mask);
		while (find != -1)
		{
			string name_check = fileinfo.name;
			if (fileinfo.attrib & _A_SUBDIR && name_check != "..")
			{
				string temp = mask;
				temp.pop_back();
				temp += fileinfo.name;
				temp += "\\*";
				findFolders(temp, word);
			}
			find = _findnext(handle, &fileinfo);
		}
		findclose(handle);
		return;
	}
	void changeDirectory(string dir);
	void remove(string path);
	void rename(string path, string name);
	void copy(string oldpath, string newpath);
	void move();
};



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
	//setlocale(LC_ALL, "Russian");


	string str = "c:\\program files\\*";
	//getline(cin, str);
	system("cls");
	FileManager fm;
	fm.showDirectory(str);
	fm.print();
	//fm.findFolders("C:\\*", "*.??");





	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());
	

}