#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class AAnimal
{
public:

    virtual ~AAnimal();

	virtual AAnimal	&operator=( const AAnimal &other ) = 0;

    virtual void makeSound(void) const = 0;
    virtual std::string getType(void) const = 0;
	virtual Brain *getBrain(void) const = 0;

protected:

    std::string _type;
    Brain *_brain;

};

#endif