#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <iostream>

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook {

private:

	std::map<std::string, ASpell*> _spells;

public:
	SpellBook() {}
	virtual ~SpellBook() {
		for(std::map<std::string, ASpell*>::const_iterator i = _spells.begin(); i != _spells.end();i++)
			delete i->second;

	}
 
	void learnSpell(ASpell *spell)
	{
		try{
			_spells.at(spell->getName());
		} catch (...)
		{
			_spells[spell->getName()] = spell->clone();
		}
	}

	void forgetSpell(const std::string name)
	{
		try{
			ASpell *spell = _spells.at(name);
			delete spell;
			_spells.erase(name);
		} catch (...)
		{
		}
	}

	ASpell *createSpell(const std::string name)
	{
		try{
			return _spells.at(name);
		} catch (...)
		{
			return NULL;
		}

	}

};


#endif

