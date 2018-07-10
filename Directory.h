//
// Created By Daniel(sisitrs2) 7/9/2018
//

#ifndef MAKEFILE_DIRECTORY_H
#define MAKEFILE_DIRECTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <memory>

class Directory
{

public:

    explicit Directory(const std::string& dir);

	const std::vector<std::string>& getCFiles() const;
	const std::unordered_set<std::string>& getHeaders() const;
	const std::string& getDir() const;

    void printFiles() const;
	bool doesHExist(const std::string& hfile) const;

private:

    std::vector<std::string> _cfiles;
    std::unordered_set<std::string> _headers; //filename, filetype
    const std::string _dir;

    std::string splitFileNameType(std::string& file) const;
    void getFiles();
    std::string exec(const std::string& cmd) const;

};

#endif //MAKEFILE_DIRECTORY_H
