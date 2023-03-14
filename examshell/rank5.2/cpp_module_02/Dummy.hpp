#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <string>
#include <iostream>

#include "ATarget.hpp"


class Dummy : public ATarget {

private:

	std::string _name;
	std::string _effects;

public:
	Dummy()
	 : ATarget("Target Practice Dummy")  { }
	virtual ~Dummy() {}
	Dummy(const Dummy &other)
 	 : ATarget(other) {	}
	Dummy &operator=(const Dummy &other)
	{ 
		ATarget::operator=(other);
		return *this;
	}
	virtual ATarget *clone(){ return new Dummy(); }
};


#endif

