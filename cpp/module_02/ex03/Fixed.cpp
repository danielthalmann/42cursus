#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &fixed) :
	_value (fixed._value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _fract;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf((value) * (float)(1 << _fract));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	_value = fixed._value;
	return *this;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)_value / (float)(1 << _fract));
}

int Fixed::toInt( void ) const
{
	return _value >> _fract;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (_value > fixed._value);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (_value < fixed._value);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (_value >= fixed._value);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (_value <= fixed._value);
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (_value == fixed._value);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (_value != fixed._value);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed value (*this);
    ++_value;
    return value;
}

Fixed &Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed value (*this);
    --_value;
    return value;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if ( a < b )
		return (a);
	else
		return (b);

}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if ( a > b )
		return (a);
	else
		return (b);
}


bool operator<(Fixed const &fixed, float const &value)
{
	return (fixed.toFloat() < value);
}

bool operator<(float const &value, Fixed const &fixed)
{
	return (value < fixed.toFloat());
}

bool operator>(Fixed const &fixed, float const &value)
{
	return (fixed.toFloat() > value);	
}

bool operator>(float const &value, Fixed const &fixed)
{
	return (value > fixed.toFloat());
}

