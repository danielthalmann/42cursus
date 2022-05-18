#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    /**
     * Operateurs d'affectation
     */
    Fixed &operator=(const Fixed& fixed);

    /**
     * Operateurs de comparaison
     */
    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;

    /**
     * Operateurs arithmétiques
     */
    Fixed operator+(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed);

   /**
    * Operateurs d'incrémentation
    */
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);


    int   getRawBits( void ) const;
    void  setRawBits( int const raw );
    
    float toFloat( void ) const;
    int   toInt( void ) const;

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int _value;
    static const int _fract = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

bool operator<(Fixed const &fixed, float const &value);
bool operator<(float const &value, Fixed const &fixed);

bool operator>(Fixed const &fixed, float const &value);
bool operator>(float const &value, Fixed const &fixed);

#endif