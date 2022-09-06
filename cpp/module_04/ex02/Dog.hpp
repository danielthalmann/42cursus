#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
public:
    Dog();
    Dog(Dog &dog);
    virtual ~Dog();
    Dog &operator=(const Dog &dog);
    virtual AAnimal	&operator=( const AAnimal &other );
    void makeSound(void) const;
    std::string getType(void) const;
    Brain *getBrain(void) const;

private:
    
};

#endif