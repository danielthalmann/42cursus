#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include "ASpell.hpp"

class Fwoosh : public ASpell
{

public:
    Fwoosh();
    ~Fwoosh();
    Fwoosh(const Fwoosh &other);
    Fwoosh &operator=(const Fwoosh &other);

public:
    virtual ASpell *clone() const;
  
};

#endif
