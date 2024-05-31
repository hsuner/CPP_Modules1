#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "CopyScavTrap " << getName() << " is born!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void ScavTrap::guardGate()
{
    if(getEnergyPoints() <= 0)
        std::cout << "ScavTrap " << getName()
            << " Don't worry, they're just sleeping!" << std::endl;
    if(getHitPoints() > 0)
        std::cout << "ScavTrap " << getName()
            << " no one will be destroyed as long as is at the gate!" << std::endl;
    else
        std::cout << "ScavTrap " << getName()
            << " don't worry, everyone is safe!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " is destroyed!" << std::endl;
}