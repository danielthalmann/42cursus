#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp")
{

}

Fireball::~Fireball()
{

}

Fireball::Fireball(const Fireball &other)
:ASpell(other)
{

}

Fireball &Fireball::operator=(const Fireball &other)
{
    ASpell::operator=(other);
    return *this;
}

ASpell *Fireball::clone() const
{
    return new Fireball();
}
