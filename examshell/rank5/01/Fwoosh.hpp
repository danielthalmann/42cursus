#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include "ASpell.hpp"

class Fwoosh : ASpell
{

public:
    Fwoosh();
    ~Fwoosh();
    Fwoosh(const ASpell &other);
    Fwoosh &operator=(const ASpell &other);



};

#endif
