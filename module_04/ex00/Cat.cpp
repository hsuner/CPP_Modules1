#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat default constructor call." << std::endl;
}

Cat::Cat (const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor call." << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

void Cat::makeSound() const{
std::cout << this->_type << " -> Meow meow" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor call." << std::endl;
}