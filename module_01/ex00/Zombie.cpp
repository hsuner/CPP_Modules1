#include "Zombie.hpp"

Zombie::Zombie(std::string str){
	this->name = str;
}

void Zombie::announce(){
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;		
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " is dead!" << std::endl;
}