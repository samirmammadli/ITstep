#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <Windows.h>
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)row, (short)col})
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct FileProp
{
	string type;
	string attr = "";
	string size_type;
	float size;
	
};

class FileManager
{
	vector<string> buffer;
	string path;
	FileProp properties;
	void getAttributes(const _finddata_t &file)
	{
		properties.size = (int(file.size*10) / 10);
		if (properties.size < 1000)
			properties.size_type = "Bytes";
		else if (properties.size < 1000000)
		{
			properties.size /= 1000;
			properties.size_type = "Kbytes";
		}
		else
		{
			properties.size /= 1000000;
			properties.size_type = "Mbytes";
		}

		file.attrib & _A_SUBDIR ? properties.type = "|<DIR>|" : properties.type = "|     |";
		properties.attr = "";
		if (file.attrib & _A_RDONLY)  properties.attr += " R ";
		if (file.attrib & _A_HIDDEN)  properties.attr += " H ";
		if (file.attrib & _A_SYSTEM)  properties.attr += " S" ;
		if (properties.attr.size() == 0) properties.attr = " Normal";

	}
public:
	FileManager(string path = "C:\\*")
	{
		this->path = path;
	}

	void showDirectory(string str)
	{
		_finddata_t fileinfo;
		int handle = _findfirst(str.c_str(), &fileinfo);
		int find = handle;
		int count = 0;
		cout << "***************************************************************************************\n";
		cout << "Name:                                        |Type:| Attr:   | Size:                  *\n";
		cout << "***************************************************************************************\n";
		while (find != -1)
		{
			count++;
			getAttributes(fileinfo);
			printf("%-45.34s%-4s%-9s| %.3g %s\n", fileinfo.name, properties.type.c_str(), properties.attr.c_str(), properties.size, properties.size_type.c_str());
			cout << "---------------------------------------------------------------------------------------\n";
			find = _findnext(handle, &fileinfo);
		}

		cout << "\nInformation: was found " << count;
		cout << " file(s) in folder..." << str << "\n\n";
		_findclose(handle);
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
	
	//FileManager fm("C:\\Windows\\System32\\");
	//fm.find("*.txt");
	//fm.changeDirectory("Debug");

	string str;
	getline(cin, str);
	system("cls");
	FileManager filemanager;
	filemanager.showDirectory(str);
	//setlocale(LC_ALL, "Russian");

	//rename("text.txt", str.c_str());
	//remove(str.c_str());

	//mkdir(str.c_str());
	//rmdir(str.c_str());
	

}