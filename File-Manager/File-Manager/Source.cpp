#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <Windows.h>
#include <windows.h>
#include <conio.h>
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})

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

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct FileProp
{
	string type;
	string attr = "";
	string size_type = "Bytes";
	double size;
};

class FileManager
{
	int textBufferSize = 25;
	vector<string> buffer;
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
		file.attrib & _A_SUBDIR ? properties.type = "|<DIR>|" : properties.type = "|file |";
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
			char temp[500];
			getAttributes(fileinfo);
			sprintf(temp, "%-45.34s%-4s%-9s| %-7.3g|%-3s|\n", fileinfo.name, properties.type.c_str(), properties.attr.c_str(), properties.size, properties.size_type.c_str());
			buffer.push_back(temp);
			find = _findnext(handle, &fileinfo);
			count++;
		}
		findclose(handle);
		/*cout << "\nInformation: was found " << count;
		cout << " file(s) in folder:  " << str << "\n\n";*/
		print();
	}
	void print()
	{
		cout << "***************************************************************************\n";
		cout << "Name:                                        |Type:| Attr:   | Size:  |   |\n";
		cout << "***************************************************************************\n";
		int i = 0;
		int index = 0;
		SetConsoleCursorPosition(h, { 0, 3 });
		while (buffer.size() != 0)
		{
			if (i == index) COLORS(BLUE, CYAN);
			cout << buffer[i];
			COLORS(CYAN, DARKBLUE);
			i++;
			if (i == buffer.size() - 1 || i % textBufferSize == 0) control(i, index);
		}
		
	}
	void control(int &i, int &index)
	{
		int key = _getch();
		if (key == 'w' && index > 0) index--;
		if (key == 's' && index < buffer.size()- 2) index++;
		i = index - index % textBufferSize;
		SetConsoleCursorPosition(h, { 0, 3 });

	}
	void findFiles(string mask);
	void changeDirectory(string dir);
	void remove(string path);
	void rename(string path, string name);
	void copy(string oldpath, string newpath);
	void move();
};

void main()
{ 
	system("color 1B");
	setlocale(LC_ALL, "Russian");
	//FileManager fm("C:\\Windows\\System32\\");
	//fm.find("*.txt");
	//fm.changeDirectory("Debug");

	string str;
	getline(cin, str);
	system("cls");
	FileManager fm;
	fm.showDirectory(str);
	

	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());
	

}