#include "Brain.hpp"

Brain::Brain () {
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "No idea!";
	std::cout << "Brain default constructor call." << std::endl;
}

Brain::Brain (const Brain &other) {
	std::cout << "Brain copy constructor call." << std::endl;
	for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other) {
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string Brain::getIdeas(int i) const {
	if (i < 0 || i > 99) {
		std::cout << "Index out of range: " << i;
		return "";
    }
    return this->ideas[i];
}

void Brain::setIdea(int i, const std::string& idea) {
    if (i < 0 || i > 99) {
        std::cout << "Index out of range: " << i << std::endl;
        return;
    }
    this->ideas[i] = idea;
}

Brain::~Brain() {
	std::cout << "Brain destructor call." << std::endl;
}