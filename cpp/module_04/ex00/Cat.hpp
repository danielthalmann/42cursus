#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat &cat);
    virtual ~Cat();
    Cat &operator=(const Cat &cat);
    void makeSound(void) const;

private:

};

#endif