#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat &cat);
    ~Cat();
    Cat &operator=(const Cat &cat);

private:

};

#endif