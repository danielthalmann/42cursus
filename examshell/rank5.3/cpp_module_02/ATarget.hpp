#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {

private:

	std::string _type;

public:
	ATarget(std::string type)
	       :_type(type)  { }
	virtual ~ATarget() {}
	ATarget(const ATarget &other)
	{
		*this = other;
	}
	ATarget &operator=(const ATarget &other)
	{ 
		_type = other._type;
		return *this;
	}

	const std::string &getType() const { return _type; }
	
	void setType(const std::string &type) { _type = type; }

	void getHitBySpell(const ASpell &spell) const;

	virtual ATarget *clone() = 0;

};


#endif

