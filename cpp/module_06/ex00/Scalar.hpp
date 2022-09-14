#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <cstdlib>
#include <tgmath.h>

class Scalar
{
public:
	Scalar();
	Scalar(Scalar &scalar);
	virtual ~Scalar();
	Scalar &operator=(const Scalar &scalar);

	void print( void );

	virtual Scalar 	*clone(void) = 0;

	virtual std::string getType(void) const = 0;
	virtual bool	canParsed(const std::string &value) const = 0;

	virtual char 	toChar(void) const;
	virtual int 	toInt(void) const;
	virtual float 	toFloat(void) const;
	virtual double 	toDouble(void) const;

	virtual void	parse(const std::string &value);
	bool	isOverflow() const;
	bool	isImpossible() const;

protected:
	double _value;
	bool   _overflow;
	bool   _impossible;


};

#endif