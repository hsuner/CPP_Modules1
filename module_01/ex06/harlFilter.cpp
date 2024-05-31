#include "harlFilter.hpp"

void Harl::debug( void ){
			std::cout << "This is [ DEBUG ] message!" << std::endl;
}
void Harl::info( void ){
			std::cout << "This is [ INFO ] message!" << std::endl;
}
void Harl::warning( void ){
			std::cout << "This is [ WARNING ] message!" << std::endl;
}
void Harl::error( void ){
			std::cout << "This is [ ERROR ] message!" << std::endl;
}
void Harl::complain(std::string level){
	std::string av[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while(i < 4)
	{
		switch(strcmp(av[i].c_str(), level.c_str()))
		{
			case 0:
				while(i < 4)
					(this->*func[i++])();
				return;
			default:
				break;
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}