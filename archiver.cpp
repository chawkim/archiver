#include "archiver.hpp"
#include <fstream>

Archiver::Archiver(std::string path): _path{path} {}

std::string file_name(std::string path){
	std::size_t p = path.find_last_of('/');
	return path.substr(p);
}

void walker(std::string path, std::vector<FileData>& fd){
	for(auto &f : std::filesystem::directory_iterator(path)){
		if(f.is_directory()){
			// std::cout << "name: " << f.path() << " | type: Directory"  << "\n";
			walker(f.path().generic_string(), fd);
		}else{
			// std::cout << "name: " << f.path() << " | type: File"  << "\n";
			FileData file = {.path =  f.path(), .size =  f.file_size()};
			fd.push_back(file);
		}  
	}
}

void Archiver::setNames(){
	std::size_t position = 0;
	while(_files[0].path[position] == _files[1].path[position])
		position++;

	for(auto i = _files.begin(); i < _files.end(); i++){
		i->name = i->path.substr(position);	
	}

}

void Archiver::readFiles(){
	walker(_path, _files);
	setNames();
}


void Archiver::arc(){
	std::ofstream of;
	std::string name = _path.substr(_path.find_last_of('/'));
	of.open(name, std::ios::binary | std::ios::out);
	for (auto i : _files) {
	
	}
}