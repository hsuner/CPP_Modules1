#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon *gun;
		std::string name;
	public:
		HumanB(std::string str) : gun(0), name(str) {} 
		void setWeapon(const Weapon &weapon);
		void attack();
};

#endif