#include "Polymorph.hpp"

Polymorph::Polymorph()
: ASpell("Polymorph", "turned into a critter")
{

}

Polymorph::~Polymorph()
{

}

Polymorph::Polymorph(const Polymorph &other)
:ASpell(other)
{

}

Polymorph &Polymorph::operator=(const Polymorph &other)
{
    ASpell::operator=(other);
    return *this;
}

ASpell *Polymorph::clone() const
{
    return new Polymorph();
}
