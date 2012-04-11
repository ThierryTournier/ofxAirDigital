#include "stdafx.h"
#include "OfTool.h"

string OfTool::currentPath = "C:";

using namespace std;

OfTool::OfTool()
{
	//
}

 int OfTool::rmFile(string fullPath)
 {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	LPCSTR aFile = const_cast<char *> (fullPath.c_str());
	//DeleteFile(aFile);
	return EXIT_SUCCESS;
 }


int OfTool::changeDirectory(string fullPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError;
	vector<string> files;
	string dir;
	string path;
	string tmp;

	LPSTR DirSpecTest = const_cast<char *> (fullPath.c_str());
	//hFind = FindFirstFile(DirSpecTest, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) 
	{
		cout << "Eh mais... Ce n'est pas un dossier." << endl;
        return (-1);
    }
	FindClose(hFind);
	currentPath = fullPath;
    return EXIT_SUCCESS;
}

int OfTool::listDir(vector<string>& dirList, vector<string>& fileList)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError;
	string dir;
	string path;

	dir += currentPath;
	LPSTR DirSpec = const_cast<char *> (dir.c_str());
	dir += "\\*";
	//hFind = FindFirstFile(DirSpec, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Eh mais... Ce n'est pas un dossier." << endl;
        return (-1);
    } 
    else
	{
		dirList.clear();
		fileList.clear();
		path = currentPath;
		path += "\\";
		//path += string(FindFileData.cFileName);
		if (path.find(".") == (size_t) (-1))
			dirList.push_back(path);
		else
			fileList.push_back(path);
        while (FindNextFile(hFind, &FindFileData) != 0)
		{
			path = currentPath;
			path += "\\";
			//path += string(FindFileData.cFileName);
			if (path.find(".") == -1)
				dirList.push_back(path);
			else
				fileList.push_back(path);
		}
		dwError = GetLastError();
		FindClose(hFind);
		if (dwError != ERROR_NO_MORE_FILES) 
		{
			cout << dwError << " erreur." << endl;
			return (-1);
		}
	}
    return EXIT_SUCCESS;
}
