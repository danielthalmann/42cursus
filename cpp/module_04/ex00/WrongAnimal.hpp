#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal &wronganimal);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &wronganimal);
    virtual void makeSound(void) const;
    std::string getType(void) const;

protected:

    std::string _type;

};

#endif