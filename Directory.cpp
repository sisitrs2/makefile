//
// Created By Daniel(sisitrs2) 7/9/2018
//

#include "Directory.h"

Directory::Directory(const std::string& dir) : _dir(dir)
{
    getFiles();
}

void Directory::printFiles() const
{
    for(const std::string& file : _cfiles)
    {
        std::cout << file << std::endl;
    }
}

bool Directory::doesHExist(const std::string& hfile) const
{
	std::unordered_set<std::string>::const_iterator got = _headers.find(hfile);
	if(got != _headers.end())
		return true;
	else
		return false;
}

const std::vector<std::string>& Directory::getCFiles() const
{
	return _cfiles;
}

const std::unordered_set<std::string>& Directory::getHeaders() const
{
	return _headers;
}

const std::string& Directory::getDir() const
{
	return _dir;
}

std::string Directory::splitFileNameType(std::string& file) const
{
    std::size_t pos;
    std::string fileType;

    pos = file.find_last_of('.');
    if(pos != std::string::npos)
    {
        fileType = file.substr(pos + 1, file.length());
        file = file.substr(0, pos);
        return( fileType ); //returns word AFTER dot.
    }
    return("");
}

void Directory::getFiles()
{
    std::string output; //store exec function output.
    std::size_t pos;
    std::string cmd = (_dir != "" ? "cd " + _dir + "; ls" : "ls");
    std::string file, type;

    output = exec(cmd); //ls - shell command that lists unhidden files and directories in directory.

    while( (pos = output.find('\n')) != std::string::npos )
    {
        file = output.substr(0, pos);
        type = splitFileNameType(file);

        if(type == "cpp")
            _cfiles.push_back(file);
        else if(type == "h")
            _headers.insert(file);

        output = output.substr(pos + 1);
    }
}

std::string Directory::exec(const std::string& cmd) const
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
