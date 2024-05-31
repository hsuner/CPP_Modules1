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
	Fixed& operator=(const Fixed &Fixed);

	Fixed operator+(const Fixed &Fixed) const;
	Fixed operator-(const Fixed &Fixed) const;
	Fixed operator*(const Fixed &Fixed) const;
	Fixed operator/(const Fixed &Fixed) const;

	bool operator==(const Fixed &Fixed) const;
	bool operator<(const Fixed &Fixed) const;
	bool operator>(const Fixed &Fixed) const;
	bool operator!=(const Fixed &Fixed) const;
	bool operator<=(const Fixed &Fixed) const;
	bool operator>=(const Fixed &Fixed) const;

	// prefix;
	Fixed	&operator++(void);
	Fixed	&operator--(void);

	// postfix;
	Fixed	operator++(int);
	Fixed	operator--(int);

	// * Min & Max;
	static Fixed		&min(Fixed &, Fixed &);
	static const Fixed	&min(const Fixed &, const Fixed &);
	static Fixed		&max(Fixed &, Fixed &);
	static const Fixed	&max(const Fixed &, const Fixed &);

	int getRawBits( void ) const ;
	void setRawBits( int const raw ) ;
	float toFloat( void ) const ;
	int toInt( void ) const ;
	~Fixed();
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif