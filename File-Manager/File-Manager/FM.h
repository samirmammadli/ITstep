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
			char tmp[MAX_PATH];
			getcwd(tmp, MAX_PATH);
			temp.buffer = tmp;
			temp.buffer += "\\";
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
		int find = handle;
		while (find != -1)
		{
			string name_check = fileinfo.name;
			if (name_check != ".." && name_check != ".")
			{
				temp.buffer = patch;
				temp.buffer.pop_back();
				temp.file = fileinfo;
				filecpy.push_back(temp);
			}
			find = _findnext(handle, &fileinfo);
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
	void RemoveFolder(string path)
	{
		path += "\\*";
		_finddata_t fileinfo;
		int handle = _findfirst(path.c_str(), &fileinfo);
		int find = handle;
		path.pop_back();
		
		while (find != -1)
		{
			string name_check = fileinfo.name;
			if (fileinfo.attrib & _A_SUBDIR && name_check != ".." && name_check != ".")
			{
				name_check = path + fileinfo.name;
				RemoveFolder(name_check);
			}
			else if (!(fileinfo.attrib & _A_SUBDIR))
			{
				name_check = path + fileinfo.name;
				remove(name_check.c_str());
			}
			find = _findnext(handle, &fileinfo);
		}
		findclose(handle);
		rmdir(path.c_str());
	}
	void Remove(string path, bool folder = false)
	{
		if (!folder)
			remove(path.c_str());
		else
			RemoveFolder(path);
	}
	void Rename(string path, string name)
	{
		rename(path.c_str(), name.c_str());
	}
	void Copy(string oldpath, string newpath)
	{
		wstring temp1 = GetWC(oldpath);
		wstring temp2 = GetWC(newpath);
		CopyFile(temp1.c_str(), temp2.c_str(), false);
	}
	void Move(string oldpath, string newpath)
	{
		MoveFile(GetWC(oldpath).c_str(), GetWC(newpath).c_str());
	}
};