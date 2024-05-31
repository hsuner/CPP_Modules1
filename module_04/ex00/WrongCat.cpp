#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor call." << std::endl;
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor call." << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << this->_type << " -> Meow meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor call." << std::endl;
}