//
// Created By Daniel(sisitrs2) 7/9/2018
//

#ifndef MAKEFILE_DIRECTORY_H
#define MAKEFILE_DIRECTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

class Directory
{

public:

	explicit Directory(const std::string& dir);

private:

	std::unordered_map<std::string, std::string> _files; //filename, filetype
	const std::string _dir;
	
	std::string splitFileNameType(std::string& file) const;
	void getFiles();
	std::string exec(const std::string& cmd) const;

};

#endif //MAKEFILE_DIRECTORY_H
