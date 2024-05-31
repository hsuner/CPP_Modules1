#include "Harl.hpp"

int main(int ac, char **av){
	Harl harl;

	switch (ac)
	{
		case 1:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 2:
			harl.complain(av[1]);
			break;
		default:
			std::cout << "Invalid argument!" << std::endl;
			break;
	}
	return 0;
}