#include "HumanB.hpp"

void HumanB::setWeapon(const Weapon &weapon){
    this->gun = (Weapon*)&weapon;
}

void HumanB::attack(){
	if (this->gun != 0)
		std::cout << this->name << " attacks with their " << this->gun->getType() << std::endl;
	else
		std::cout << this->name << " doesn't have a weapon to attack." << std::endl;
}