#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "CopyFragTrap " << getName() << " is born!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    if(getEnergyPoints() > 0)
        std::cout << "FragTrap " << getName() << " says: Gimme five!" << std::endl;
    else
        std::cout << "FragTrap " << getName() << " can't give high five. No energy points!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " is destroyed!" << std::endl;
}