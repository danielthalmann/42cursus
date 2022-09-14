#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <cstdlib>


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
	virtual void	parse(const std::string &value) = 0;
	virtual bool	canParsed(const std::string &value) const = 0;

	virtual char 	toChar(void) const = 0;
	virtual int 	toInt(void) const = 0;
	virtual float 	toFloat(void) const = 0;
	virtual double 	toDouble(void) const = 0;

	bool	isOverflow() const;
	bool	isImpossible() const;

protected:
	double _value;
	bool   _overflow;
	bool   _impossible;


};

#endif