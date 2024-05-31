#include "Fixed.hpp"

Fixed::Fixed(): num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		this->num = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void Fixed::setRawBits( int const raw ){
	this->num = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
