#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <Windows.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
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



class Printing {
	enum figPos {
		VERTICAL, HORIZONTAL, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT
	};
	  char* symbols;
	
public:
	Printing()
	{
		symbols = new  char[6];
		symbols[VERTICAL] = 186;
		symbols[HORIZONTAL] = 205;
		symbols[UPLEFT] = 201;
		symbols[UPRIGHT] = 187;
		symbols[DOWNLEFT] = 200;
		symbols[DOWNRIGHT] = 188;
	}
	void  printTable(int width = 0, int height = 0, int indentW = 0, int indentH = 0)
	{
		setlocale(LC_ALL, "C");
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
		setlocale(LC_ALL, "Rus");
	}
	void printText(int indentH, int indentW, Colors bg, Colors fg, string text)
	{
		COORDS(indentH, indentW);
		COLORS(fg, bg);
		cout << text;
		COLORS(CYAN, DARKBLUE);
	}
};

struct FileProp
{
	string type;
	string attr = "";
	string size_type = "Bytes";
	string time_c;
	string time_w;
	string time_a;
	double size;
};

struct FileInfoCopy
{
	string buffer;
	_finddata_t file;
};

class FileManager
{
	Printing Print;
	int textBufferSize = 25;
	vector<FileInfoCopy> filecpy;
	string path;
	FileProp *properties;
	FileManager(const FileManager &f)
	{
		this->properties = new FileProp;
		memcpy(this->properties, f.properties, sizeof(FileProp));
		this->Print = f.Print;
		this->textBufferSize = f.textBufferSize;
		this->path = f.path;
		this->filecpy = f.filecpy;
	}
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
		if (file.attrib & _A_SYSTEM)  properties->attr += " S" ;
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
	FileManager(string path = "C:\*")
	{
		this->path = path;
		properties = new FileProp;
	}
	~FileManager()
	{
		delete properties;
	}

	void showDirectory(string &str)
	{
		FileInfoCopy temp;
		filecpy.clear();
		_finddata_t fileinfo;
		int handle = _findfirst(str.c_str(), &fileinfo);
		int find = handle;
		int count = 0;
		if (handle == -1) (str.pop_back(), str += "\\..\\*");
		while (find != -1)
		{
			char buffer[500];
			sprintf(buffer, "%-76.70s", fileinfo.name);
			temp.buffer = fileinfo.name;//temp.buffer = buffer;
			temp.file = fileinfo;
			filecpy.push_back(temp);
			find = _findnext(handle, &fileinfo);
			count++;
		}
		
		findclose(handle);
	}
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
			for (;filecpy.size() != 0; i++)
			{
				if (filecpy[i].file.attrib & _A_SUBDIR)
					COLORS(WHITE, DARKBLUE);
				else if (filecpy[i].file.attrib & _A_HIDDEN)
					COLORS(DARKCYAN, DARKBLUE);
				if (i == cursor)
				{
					getAttributes(filecpy[i].file);
					printInfo();
					COLORS(BLACK, DARKCYAN);
				}
				COORDS(short(i % textBufferSize + 1), 2);
				cout << filecpy[i].buffer;
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
					Remove(str + filecpy[cursor].file.name);
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
			if (key == 13 && (filecpy[cursor].file.attrib & _A_SUBDIR))
			{
				chdir(filecpy[cursor].file.name);
				system("cls");
				return;
			}
				
			if (cursor % textBufferSize == 0 && key == 80 || (cursor % textBufferSize == textBufferSize -1 && key == 72) && cursor != 0)
			{
				system("cls");
				printFrame();
				Print.printText(27, 16, DARKBLUE, CYAN, temp);
			}
			i = cursor - cursor % textBufferSize;
		}
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
	void changeDirectory(string dir)
	{

	}
	void Remove(string path)
	{
		remove(path.c_str());
	}
	void Rename(string path, string name);
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


	char dir[MAX_PATH];
	getcwd(dir, 255);
	setlocale(LC_ALL, "Rus");
	string str = dir;
	str += "\\*";
	system("cls");
	str = "C:\\*";
	FileManager fm;
	while (true)
	{
		fm.showDirectory(str);
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