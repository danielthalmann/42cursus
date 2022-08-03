#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog &dog);
    virtual ~Dog();
    Dog &operator=(const Dog &dog);
    void makeSound(void) const;

private:
    Brain *_brain;
    
};

#endif