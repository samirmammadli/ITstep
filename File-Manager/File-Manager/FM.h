#pragma once
#include "Printing.h"


class FileManager
{

public:

	 void showDirectory(string &str, vector<FileInfoCopy> &filecpy)
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
			temp.file = fileinfo;
			filecpy.push_back(temp);
			find = _findnext(handle, &fileinfo);
			count++;
		}
		findclose(handle);
	}
	
	void findFiles(string mask, string patch, vector<FileInfoCopy> &filecpy)
	{
		FileInfoCopy temp;
		_finddata_t fileinfo;
		int handle = _findfirst(mask.c_str(), &fileinfo);
		int find = -1;
		if (handle != -1) find = _findnext(handle, &fileinfo);
		if (handle != -1) find = _findnext(handle, &fileinfo);
		if (find != -1)
		{
			temp.buffer = patch;
			temp.file = fileinfo;
			filecpy.push_back(temp);
		}
		findclose(handle);
	}
	void findFolders(string mask, string word, vector<FileInfoCopy> &filecpy)
	{
		_finddata_t fileinfo;
		int handle = _findfirst(mask.c_str(), &fileinfo);
		int find = -1;
		if (handle != -1) find = _findnext(handle, &fileinfo);
		string temp = mask;
		temp.pop_back();
		temp += word;
		findFiles(temp, mask, filecpy);
		while (find != -1)
		{
			string name_check = fileinfo.name;
			if (fileinfo.attrib & _A_SUBDIR && name_check != "..")
			{
				string temp = mask;
				temp.pop_back();
				temp += fileinfo.name;
				temp += "\\*";
				findFolders(temp, word, filecpy);
			}
			find = _findnext(handle, &fileinfo);
		}
		findclose(handle);
	}
	void Remove(string path)
	{
		remove(path.c_str());
	}
	void Rename(string path, string name);
	void copy(string oldpath, string newpath);
	void move();
};