#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
public:

    virtual void makeSound(void) const = 0;
    virtual std::string getType(void) const = 0;
    virtual ~Animal() = 0;

protected:

    std::string _type;
    Brain *_brain;

};

#endif