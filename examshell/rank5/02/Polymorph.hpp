#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"

class Polymorph : public ASpell
{

public:
    Polymorph();
    ~Polymorph();
    Polymorph(const Polymorph &other);
    Polymorph &operator=(const Polymorph &other);

public:
    virtual ASpell *clone() const;
  
};

#endif
