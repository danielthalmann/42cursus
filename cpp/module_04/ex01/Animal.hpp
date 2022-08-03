#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(Animal &animal);
    virtual ~Animal();
    Animal &operator=(const Animal &animal);
    virtual void makeSound(void) const;
    std::string getType(void) const;

protected:

    std::string _type;

};

#endif