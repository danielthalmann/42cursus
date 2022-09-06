#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
public:
    Cat();
    Cat(Cat &cat);
    virtual ~Cat();
    virtual AAnimal	&operator=( const AAnimal &other );
    Cat &operator=(const Cat &cat);
    void makeSound(void) const;
    std::string getType(void) const;
    Brain *getBrain(void) const;

private:
    
};

#endif