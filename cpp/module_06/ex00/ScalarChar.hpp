#ifndef SCALARCHAR_HPP
#define SCALARCHAR_HPP

#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarChar : public Scalar
{
public:
	ScalarChar();
	ScalarChar(ScalarChar &obj);
	virtual ~ScalarChar();
	ScalarChar &operator=(const ScalarChar &obj);

	virtual Scalar 	*clone(void);
	
	virtual void	parse(const std::string &value);
	virtual std::string getType(void) const;
	virtual bool	canParsed(const std::string &value) const;

private:

};

#endif