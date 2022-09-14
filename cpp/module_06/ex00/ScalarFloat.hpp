#ifndef SCALARFLOAT_HPP
#define SCALARFLOAT_HPP

#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarFloat : public Scalar
{
public:
	ScalarFloat();
	ScalarFloat(ScalarFloat &obj);
	virtual ~ScalarFloat();
	ScalarFloat &operator=(const ScalarFloat &obj);

	virtual Scalar 	*clone(void);

	virtual std::string getType(void) const;
	virtual bool	canParsed(const std::string &value) const;

private:

};

#endif