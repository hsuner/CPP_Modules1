#include "AAnimal.hpp"

AAnimal::AAnimal () {
	this->_type = "AAnimal";
	std::cout << "AAnimal default constructor call." << std::endl;
}

AAnimal::AAnimal (std::string type) : _type(type) {
	this->_type = "AAnimal";
	std::cout << "AAnimal parameter constructor call." << std::endl;
}

AAnimal::AAnimal (const AAnimal &other) : _type(other._type){
	std::cout << "AAnimal copy constructor call." << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void AAnimal::makeSound() const{
	std::cout << this->_type << " -> AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const{
	return this->_type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor call." << std::endl;
}