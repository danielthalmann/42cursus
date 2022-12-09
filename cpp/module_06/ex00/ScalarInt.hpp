#ifndef SCALARINT_HPP
#define SCALARINT_HPP

#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarInt : public Scalar
{
public:
	ScalarInt();
	ScalarInt(ScalarInt &obj);
	virtual ~ScalarInt();
	ScalarInt &operator=(const ScalarInt &obj);

	virtual Scalar 	*clone(void);

	virtual std::string getType(void) const;
	virtual bool	canParsed(const std::string &value) const;

private:

};

#endif