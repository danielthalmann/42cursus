#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(WrongCat &wrongcat);
    virtual ~WrongCat();
    WrongCat &operator=(const WrongCat &wrongcat);
    void makeSound(void) const;

private:

};

#endif