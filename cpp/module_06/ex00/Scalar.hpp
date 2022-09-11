#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

class ScalarInt;




class Scalar
{
public:
	virtual void parse(const std::string &value) = 0;
	virtual bool canParsed(const std::string &value) const = 0;
	virtual std::string getType() const = 0;

	ScalarInt toInt() const;

	static void convert(std::string s);

protected:
	std::string	_type;
	double		_value;

};

#endif