#include "ASpell.hpp"


ASpell::ASpell(const std::string &n, const std::string &e)
: name(n), effects(e)
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
    name = other.name;
    effects = other.effects;
    return *this;
}

void ASpell::launch(ATarget &target)
{
    target.getHitBySpell(*this);
}

const std::string &ASpell::getName() const
{
    return name;
}
const std::string &ASpell::getEffects() const
{
    return effects;
}
