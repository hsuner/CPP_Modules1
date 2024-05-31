#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace {
	private:
		std::string filename;
		std::string s1;
		std::string s2;
	public:
		Replace(std::string av1, std::string av2, std::string av3);
		int replaceInFile();
};

#endif