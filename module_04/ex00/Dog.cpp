#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor call." << std::endl;
}

Dog::Dog (const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor call." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void Dog::makeSound() const{
std::cout << this->_type << " -> Hav hav" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor call." << std::endl;
}