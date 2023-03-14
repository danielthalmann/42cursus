#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {

private:

	std::string _name;
	std::string _title;
	SpellBook _book;	

public:
	Warlock(std::string name, std::string title)
	       :_name(name), _title(title) {
		       std::cout << _name << ": This looks like another boring day." << std::endl ;
	       }
	virtual ~Warlock() {
		std::cout << _name << ": My job here is done!" << std::endl;
	}
	Warlock(const Warlock &other)
	{
		*this = other;
	}
	Warlock &operator=(const Warlock &other)
	{ 
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
		_book.learnSpell(spell);
	}

	void forgetSpell(const std::string name)
	{
		_book.forgetSpell(name);
	}

	void launchSpell(const std::string name, ATarget& target)
	{

		ASpell *spell = _book.createSpell(name);
		if (spell)
			spell->launch(target);

	}

};


#endif

