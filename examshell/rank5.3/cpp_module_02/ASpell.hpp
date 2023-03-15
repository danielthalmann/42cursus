#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell {

private:

	std::string _name;
	std::string _effects;

public:
	ASpell(std::string name, std::string effects)
	       :_name(name), _effects(effects)  { }
	virtual ~ASpell() {}
	ASpell(const ASpell &other)
	{
		*this = other;
	}
	ASpell &operator=(const ASpell &other)
	{ 
		_name = other._name;
		_effects = other._effects;
		return *this;
	}

	const std::string &getName() const { return _name; }
	const std::string &getEffects() const { return _effects; }
	
	void setName(const std::string &name) { _name = name; }
	void setEffects(const std::string &effects) { _effects = effects; }

	virtual ASpell *clone() = 0;

	void launch(const ATarget &target)const ;
};


#endif

