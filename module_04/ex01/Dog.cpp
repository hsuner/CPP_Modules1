#include "Dog.hpp"

Dog::Dog() {
	this->brain = new Brain;
	this->_type = "Dog";
	std::cout << "Dog default constructor call." << std::endl;
}

Dog::Dog (const Dog &other) {
	std::cout << "Dog copy constructor call." << std::endl;
	this->brain = new Brain(*other.brain);
	this->_type = "Dog";
}



Dog& Dog::operator=(const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if(this != &other) {
	 	delete this->brain;
        this->brain = new Brain(*other.brain);
		this->_type = "Dog";
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << this->_type << " -> Hav hav" << std::endl;
}

std::string Dog::getBrainIdea(int i) const {
	return this->brain->getIdeas(i);
}

void Dog::setBrainIdea(int i, const std::string& idea) {
    this->brain->setIdea(i, idea);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor call." << std::endl;
}