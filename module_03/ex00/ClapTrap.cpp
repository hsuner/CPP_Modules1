#include "ClapTrap.hpp"

ClapTrap::ClapTrap () : hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string &str) : name(str), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage) {
    std::cout << "CopyClapTrap " << name << " is born!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
	if(this->attack_damage > 0) {
		if(hit_points > 0 && energy_points > 0) {
			std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;		
			energy_points--;
		}
		else {
			std::cout << "Not enough energy points or hit points to perform the attack!" << std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if(amount > 0) {
		if(hit_points > 0 && energy_points > 0) {
			std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
			hit_points -= amount;
			if(hit_points < 0)
				hit_points = 0;
		}
		else {
			std::cout << "ClapTrap " << name << " has no hit points left!" << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if(amount > 0) {
		if(hit_points > 0 && energy_points > 0) {
			std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
			hit_points += amount;
			energy_points--;
			if(hit_points < 0)
				hit_points = 0;
		}
		else {
			std::cout << "ClapTrap " << name << " already has full hit points!" << std::endl;
		}
	}
}

void ClapTrap::setAttackDamage(int amount) {
	this->attack_damage = amount;
}

int ClapTrap::getEnergyPoints() const {
	return energy_points;
}

int ClapTrap::getHitPoints() const {
	return hit_points;
}

std::string ClapTrap::getName() const {
	return name;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
}