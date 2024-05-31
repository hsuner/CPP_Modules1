#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon &gun;
		std::string name;
	public:
		HumanA(std::string str, Weapon &weapon) : gun(weapon), name(str) {}
		void attack();
};

#endif