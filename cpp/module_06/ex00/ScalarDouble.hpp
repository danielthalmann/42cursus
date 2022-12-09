#ifndef SCALARFDOUBLE_HPP
#define SCALARFDOUBLE_HPP

#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarDouble : public Scalar
{
public:
	ScalarDouble();
	ScalarDouble(ScalarDouble &obj);
	virtual ~ScalarDouble();
	ScalarDouble &operator=(const ScalarDouble &obj);

	virtual Scalar 	*clone(void);
	virtual void parse(const std::string &value);

	virtual std::string getType(void) const;
	virtual bool	canParsed(const std::string &value) const;

private:


};

#endif