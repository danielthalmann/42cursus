#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
    bool operator>(const Fixed& fixed);
    bool operator<(const Fixed& fixed);
    bool operator>=(const Fixed& fixed);
    bool operator<=(const Fixed& fixed);
    bool operator==(const Fixed& fixed);
    bool operator!=(const Fixed& fixed);

    /**
     * Operateurs arithmétiques
     */
    Fixed &operator+(const Fixed& fixed);
    Fixed &operator-(const Fixed& fixed);
    Fixed &operator*(const Fixed& fixed);
    Fixed &operator/(const Fixed& fixed);

   /**
    * Operateurs d'incrémentation
    */


    int   getRawBits( void ) const;
    void  setRawBits( int const raw );
    
    float toFloat( void ) const;
    int   toInt( void ) const;

private:
    int _value;
    static const int _fract = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif