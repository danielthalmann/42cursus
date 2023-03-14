
#include "Warlock.hpp"

Warlock::Warlock()
: _name("noname"), _title("notitle")
{

}

Warlock::Warlock(const std::string &n, const std::string &t)
: _name(n), _title(t)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock& other)
{
    *this = other;
}

Warlock &Warlock::operator=(const Warlock& other)
{
    _name = other._name;
    _title = other._title;
    
    for(std::map<std::string, ASpell*>::const_iterator i = other._spells.begin(); i != other._spells.end(); i++)
        _spells[i->first] = i->second->clone();

    return *this;

}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getTitle() const
{
    return _title;
}

const std::string &Warlock::getName() const
{
    return _name;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::setTitle(const std::string &t)
{
    _title = t;
}

void Warlock::learnSpell(ASpell* spell)
{
    _book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &s)
{
    _book.forgetSpell(s);
}

void Warlock::launchSpell(const std::string &s, ATarget &target)
{
    try {
        ASpell * spell = _book.createSpell(s);
        spell->launch(target);
    } catch(...)
    {

    }
}
