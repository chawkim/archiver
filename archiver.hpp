#ifndef _ARCHIVER_HPP
#define _ARCHIVER_HPP

#include <cstdint>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

struct FileData{
	std::string 				path;
	std::size_t 				size;
	std::string 				name;
	std::vector<std::uint8_t> 	contents;
};

class Archiver{
private:
	std::vector<FileData> 	_files;
	std::string 			_path;

	void setNames();

public:
	Archiver(std::string);
	void readFiles();
	void arc();
	void narc();
};

#endif  // _ARCHIVER_HPP