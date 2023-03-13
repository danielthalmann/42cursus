#include "ASpell.hpp"


ASpell::ASpell(const std::string &n, const std::string &e)
: _name(n), _effects(e)
{

}

ASpell::~ASpell()
{

}

ASpell::ASpell(const ASpell& other)
{
    *this = other;
}

ASpell &ASpell::operator=(const ASpell& other)
{
    _name = other._name;
    _effects = other._effects;
    return *this;
}

void ASpell::launch(ATarget &target)
{
    target.getHitBySpell(*this);
}

const std::string &ASpell::getName() const
{
    return _name;
}
const std::string &ASpell::getEffects() const
{
    return _effects;
}
