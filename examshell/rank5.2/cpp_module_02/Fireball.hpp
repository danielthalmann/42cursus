#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"


class Fireball : public ASpell {

public:
	Fireball()
	 : ASpell("Fireball", "fwooshed")  { }
	virtual ~Fireball() {}
	Fireball(const Fireball &other)
 	 : ASpell(other) {	}
	Fireball &operator=(const Fireball &other)
	{ 
		ASpell::operator=(other);
		return *this;
	}
	virtual ASpell *clone(){ return new Fireball(); }
};


#endif

