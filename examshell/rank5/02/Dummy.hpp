
#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "Atarget.hpp"

class Dummy : public ATarget
{

public:
    Dummy();
    ~Dummy();
    Dummy(const Dummy &other);
    Dummy &operator=(const Dummy &other);

public:
    ATarget *clone() const;

};

#endif
