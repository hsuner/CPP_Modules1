#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int num;
		static const int bit = 8;
	public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num2);
	Fixed(const Fixed& other);
	Fixed& operator=(Fixed const &Fixed);
	int getRawBits( void ) const ;
	void setRawBits( int const raw ) ;
	float toFloat( void ) const ;
	int toInt( void ) const ;
	~Fixed();
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif