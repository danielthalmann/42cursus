#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(Animal &animal);
    ~Animal();
    Animal &operator=(const Animal &animal);

private:
    std::string _type;

};

#endif