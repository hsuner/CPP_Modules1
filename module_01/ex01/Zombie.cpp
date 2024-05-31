#include "Zombie.hpp"

void Zombie::announce(){
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;		
}

void Zombie::setName(std::string name){
	this->_name = name;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->_name << " is dead!" << std::endl;
}