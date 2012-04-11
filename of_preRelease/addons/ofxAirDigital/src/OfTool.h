#ifndef OfTool_H
#define OfTool_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <malloc.h>
#include <errno.h>

using namespace std;
using std::string;

class OfTool
{
    public:
        OfTool();

        /* accesseur */
        string get_currentPath() const {return currentPath;}
        void set_currentPath(string aCurrentPath) {this->currentPath = aCurrentPath;}
		/* autres methodes */
        int rmFile(string fullPath);
        int changeDirectory(string fullPath);
        int listDir(vector<string>& dirList, vector<string>& fileList);

    protected:
    private:
        static string currentPath;
};

#endif // OfTool_H
