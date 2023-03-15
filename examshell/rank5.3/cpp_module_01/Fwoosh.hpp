#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell {

public:
	Fwoosh() :ASpell("Fwoosh", "fwooshed") { }
	virtual ~Fwoosh() {	}
	Fwoosh(const Fwoosh &other) : ASpell(other) { }
	Fwoosh &operator=(const Fwoosh &other)
	{
		ASpell::operator=(other);
		return *this;
	}
	virtual ASpell *clone() const { return new Fwoosh(*this); };
};


#endif

