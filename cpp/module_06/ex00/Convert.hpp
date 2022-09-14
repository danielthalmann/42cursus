#ifndef CONVERT_HPP
#define CONVERT_HPP

#include "Scalar.hpp"
#include "ScalarChar.hpp"
#include "ScalarInt.hpp"
#include "ScalarFloat.hpp"

#include <iostream>

class Convert
{
public:

	Convert();
	Convert(Convert &convert);
	virtual ~Convert();
	Convert &operator=(const Convert &convert);

	Scalar *scalar(std::string s);

	class ConversionNotPossibleException : public std::exception
	{
	public:
		const char *what () const throw () {
			return ("conversion is not possible");
		}
	};

	static const int scalar_length = 3;

protected:

	Scalar *_scalar[Convert::scalar_length];

};

#endif