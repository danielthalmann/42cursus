#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog &dog);
    ~Dog();
    Dog &operator=(const Dog &dog);

private:

};

#endif