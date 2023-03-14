#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {

private:

	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*> _spells;

public:
	Warlock(std::string name, std::string title)
	       :_name(name), _title(title) {
		       std::cout << _name << ": This looks like another boring day." << std::endl ;
	       }
	virtual ~Warlock() {
		std::cout << _name << ": My job here is done!" << std::endl;
		for(std::map<std::string, ASpell*>::const_iterator i = _spells.begin(); i != _spells.end();i++)
			delete i->second;

	}
	Warlock(const Warlock &other)
	{
		*this = other;
	}
	Warlock &operator=(const Warlock &other)
	{ 
		for(std::map<std::string, ASpell*>::const_iterator i = _spells.begin(); i != _spells.end();i++)
			delete i->second;
		_spells.clear();
		for(std::map<std::string, ASpell*>::const_iterator i = other._spells.begin(); i != other._spells.end();i++)
			_spells[i->first] = i->second->clone();

		_name = other._name;
		_title = other._title;
		return *this;
	}

	void introduce() const 
	{
		std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
	}

	const std::string &getName() const { return _name; }
	const std::string &getTitle() const { return _title; }
	
	void setName(const std::string &name) { _name = name; }
	void setTitle(const std::string &title) { _title = title; }
 
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

	void launchSpell(const std::string name, ATarget& target)
	{
		try{
			ASpell *spell = _spells.at(name);
			spell->launch(target);
		} catch (...)
		{
		}

	}

};


#endif

