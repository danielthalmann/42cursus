#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice &ice);
    virtual ~Ice();
    Ice &operator=(const Ice &ice);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);

private:

};

#endif