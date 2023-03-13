#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::~Fwoosh()
{

}

Fwoosh::Fwoosh(const Fwoosh &other)
:ASpell(other)
{

}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
    ASpell::operator=(other);
    return *this;
}

ASpell *Fwoosh::clone() const
{
    return new Fwoosh();
}
