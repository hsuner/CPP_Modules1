#include "Animal.hpp"

Animal::Animal () {
	this->_type = "Animal";
	std::cout << "Animal default constructor call." << std::endl;
}

Animal::Animal (std::string type) : _type(type) {
	this->_type = "Animal";
	std::cout << "Animal parameter constructor call." << std::endl;
}

Animal::Animal (const Animal &other) : _type(other._type){
	std::cout << "Animal copy constructor call." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void Animal::makeSound() const{
	std::cout << this->_type << " -> animal sound" << std::endl;
}

std::string Animal::getType() const{
	return this->_type;
}

Animal::~Animal() {
	std::cout << "Animal destructor call." << std::endl;
}