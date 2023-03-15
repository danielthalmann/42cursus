#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"


class Polymorph : public ASpell {

public:
	Polymorph()
	 : ASpell("Polymorph", "turned into a critter")  { }
	virtual ~Polymorph() {}
	Polymorph(const Polymorph &other)
 	 : ASpell(other) {	}
	Polymorph &operator=(const Polymorph &other)
	{ 
		ASpell::operator=(other);
		return *this;
	}
	virtual ASpell *clone(){ return new Polymorph(*this); }
};


#endif

