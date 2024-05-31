#include "harlFilter.hpp"

int main(int ac, char **av){
	Harl harl;

	switch (ac)
	{
		case 2:
			harl.complain(av[1]);
			break;
		default:
			std::cout << "[ ERROR ]\n" << "Just use: \"DEBUG\", \"INFO\", \"WARNING\" or \"ERROR\"" << std::endl;
			break;
	}
	return 0;
}