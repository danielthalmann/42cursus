#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{

}

Dummy::Dummy(const Dummy &other)
: ATarget(other)
{

}

Dummy &Dummy::operator=(const Dummy &other)
{
    ATarget::operator=(other);
    return *this;
}

ATarget *Dummy::clone() const
{
    return new Dummy();
}
