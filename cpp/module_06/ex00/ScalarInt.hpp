#ifndef SCALARINT_HPP
#define SCALARINT_HPP

#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>

class ScalarInt : public Scalar
{
public:
	ScalarInt();
	ScalarInt(ScalarInt &obj);
	virtual ~ScalarInt();
	ScalarInt &operator=(const ScalarInt &obj);

	virtual Scalar 	*clone(void);

	virtual std::string getType(void) const;
	virtual void	parse(const std::string &value);
	virtual bool	canParsed(const std::string &value) const;

	virtual char 	toChar(void) const;
	virtual int 	toInt(void) const;
	virtual float 	toFloat(void) const;
	virtual double 	toDouble(void) const;

private:
	int _value;

};

std::ostream &operator<<(std::ostream &out, ScalarInt const &value);

#endif