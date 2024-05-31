#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () {
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor call." << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &other) : _type(other._type){
	std::cout << "WrongAnimal copy constructor call." << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << this->_type << " -> wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor call." << std::endl;
}