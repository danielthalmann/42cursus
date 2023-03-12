
#include "Warlock.hpp"

Warlock::Warlock()
: name("noname"), title("notitle")
{

}

Warlock::Warlock(const std::string &n, const std::string &t)
: name(n), title(t)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getTitle() const
{
    return title;
}

const std::string &Warlock::getName() const
{
    return name;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::setTitle(const std::string &t)
{
    title = t;
}


void Warlock::learnSpell(ASpell* spell)
{
    _spells[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string s)
{
    _spells.erase(s);
}

void Warlock::launchSpell(std::string s, ATarget &target)
{
    try {
        ASpell * spell = _spells.at(s);
        target.getHitBySpell(*spell);
    } catch(...)
    {

    }
}
