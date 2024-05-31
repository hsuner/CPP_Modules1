#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string str) : type(str) {}
		const std::string& getType();
		void setType(const std::string& str);
};

#endif