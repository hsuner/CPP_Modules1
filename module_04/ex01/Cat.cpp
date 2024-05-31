#include "Cat.hpp"

Cat::Cat() {
	this->brain = new Brain;
	this->_type = "Cat";
	std::cout << "Cat default constructor call." << std::endl;
}

Cat::Cat (const Cat &other) {
	std::cout << "Cat copy constructor call." << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if(this != &other) {
	 	delete this->brain;
        this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const{
std::cout << this->_type << " -> Meow meow" << std::endl;
}

std::string Cat::getBrainIdea(int i) const {
	return this->brain->getIdeas(i);
}

void Cat::setBrainIdea(int i, const std::string& idea) {
    this->brain->setIdea(i, idea);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructure call." << std::endl;
}