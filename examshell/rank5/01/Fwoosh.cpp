#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh")
{

}

Fwoosh::~Fwoosh()
{

}

Fwoosh::Fwoosh(const Fwoosh &other)
{

}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
    return *this;
}

ASpell *Fwoosh::clone() const
{
    return new Fwoosh();
}
