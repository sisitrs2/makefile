//
// Created By Daniel(sisitrs2) 7/9/2018
//

#include <iostream>
#include "FileEdit.h"
#include "Directory.h"

using std::cout;
using std::endl;

void makefile(const Directory& dir);
const std::string getMFilePath(const std::string& dirPath);

int main(int argc, char* argv[])
{
    Directory dir(argc > 1 ? argv[1] : "");
	makefile(dir);

    return 0;
}


void makefile(const Directory& dir)
{
	const std::string mfilePath = getMFilePath(dir.getDir());
	FileEdit mfile(mfilePath);
	std::string ofiles;

	cout << "makefile created at: " << mfilePath << endl;

	mfile << "";
	for(const std::string& file : dir.getCFiles())
	{
		ofiles += " " + file + ".o";
	}
	mfile << ("run:" + ofiles);
	mfile << ("\tg++" + ofiles + " -o run\n");
	
	for(const std::string& file : dir.getCFiles())
	{
		mfile << (file + ".o: " + file + ".cpp " + (dir.doesHExist(file) ? file + ".h" : ""));
		mfile << ("\tg++ -c " + file + ".cpp\n");
	}

	mfile << "clear:";
	mfile << "\trm *.o run";
}

const std::string getMFilePath(const std::string& dirPath)
{
	std::string path = dirPath;
	unsigned int lastChar = path.length() - 1;

	if(path[lastChar] != '/')
		path += '/';
	path += "makefile";

	return path;
}

