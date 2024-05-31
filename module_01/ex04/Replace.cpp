#include "Replace.hpp"

Replace::Replace(std::string av1, std::string av2, std::string av3){
	this->filename = av1;
	this->s1 = av2;
	this->s2 = av3;
}

int Replace::replaceInFile(){
	std::string content;
	size_t pos = 0;
	bool fileIsEmpty = true;
	bool s1Found = false;

	std::ifstream ifile(this->filename.c_str());
	if(!ifile.is_open()) {
		std::cout << "Error: Failed to open input file '" << this->filename << "'" << std::endl;
		return 1;
	}
	std::ofstream ofile((this->filename + ".replace").c_str());
	if(!ofile.is_open()) {
		std::cout << "Error: Failed to open input file '" << this->filename << "'" << ".replace" << std::endl;
		return 1;
	}
	while(getline(ifile, content)) {
		pos = 0;
        while ((pos = content.find(this->s1, pos)) != std::string::npos) {
            content.erase(pos, this->s1.length());
            content.insert(pos, this->s2);
            pos += this->s2.length();
			if (!s1Found)
                s1Found = true;
		}
		if (!ifile.eof())
			content += '\n';
		ofile << content;
		fileIsEmpty = false;
	}
	if (fileIsEmpty) {
        std::cout << "Error: Input file is empty." << std::endl;
		ofile.close();
		std::remove((this->filename + ".replace").c_str());
		return 1;
    }
	if (!s1Found){
		std::cout << "Error: Word not found in the file." << std::endl;
		ofile.close();
		std::remove((this->filename + ".replace").c_str());
		return 1;
	}
	std::cout << "Replacement completed. Output file: " << this->filename + ".replace" << std::endl;
	return 0;
}
