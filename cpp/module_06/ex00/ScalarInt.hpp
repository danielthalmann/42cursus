#ifndef SCALARINT_HPP
#define SCALARINT_HPP

#include "Scalar.hpp"
#include <iostream>

class ScalarInt : public Scalar
{
public:
	ScalarInt();
	ScalarInt(double value);
	ScalarInt(ScalarInt &scalarint);
	virtual ~ScalarInt();
	ScalarInt &operator=(const ScalarInt &scalarint);

	virtual void parse(const std::string &value);
	virtual bool canParsed(const std::string &value) const;
	virtual std::string getType() const;

private:

};

#endif