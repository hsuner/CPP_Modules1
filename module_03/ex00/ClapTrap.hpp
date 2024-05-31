#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(const std::string &str);
		ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setAttackDamage(int amount);
		int getEnergyPoints() const;
        int getHitPoints() const;
        std::string getName() const;

		~ClapTrap();
};

#endif