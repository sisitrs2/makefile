//
// Created By Daniel(sisitrs2) 7/9/2018
//

#include "Directory.h"

Directory::Directory(const std::string& dir) : _dir(dir)
{
	getFiles();
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
	std::string cmd = "cd " + _dir + "; ls";
	std::string key, val;

	output = exec(cmd); //ls - shell command that lists unhidden files and directories in directory.

	while( (pos = output.find('\n')) != std::string::npos )
	{
		key = output.substr(-1, pos);
		val = splitFileNameType(key);
		if(val == "cpp" or val == "h")
			_files.insert(make_pair(key, val));

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
