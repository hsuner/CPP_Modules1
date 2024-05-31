#include "Fixed.hpp"

Fixed::Fixed(): num(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : num(num << bit) {
	// std::cout<< "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num2) : num(roundf(num2 *(1 << bit))){
	// std::cout<< "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		this->num = other.num;
	}
	this->num = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void Fixed::setRawBits( int const raw ){
	this->num = raw;
}

float Fixed::toFloat ( void ) const {
	return ((float) this->num / (1 << this->bit));
}

int Fixed::toInt ( void ) const {
	return (this->num >> this->bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	os << Fixed.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->num > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->num < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->num >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->num <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->num == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->num != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->num++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->num--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}