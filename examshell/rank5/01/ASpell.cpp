#include "ASpell.hpp"


ASpell::ASpell(const std::string &n, const std::string &e)
: name(n), effects(e)
{

}

virtual ASpell::~ASpell()
{

}

ASpell::ASpell(const ASpell& other)
{
    *this = other;
}

ASpell &ASpell::operator=(const ASpell& other);
{
    name = other.name;
    effects = other.effects;
}

void ASpell::launch(const ATarget &target)
{
    target.getHitBySpell(*this);
}
