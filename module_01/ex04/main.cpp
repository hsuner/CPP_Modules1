#include "Replace.hpp"

int main(int ac, char **av)
{
	if(ac == 4) {
		Replace replace(av[1], av[2], av[3]);
		replace.replaceInFile();
	}
	else {
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	return 0;
}