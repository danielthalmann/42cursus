#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{

public:
    Character();
    Character(std::string name);
    Character(Character &character);
    virtual ~Character();
    Character &operator=(const Character &character);

    virtual std::string const &getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

protected:

    std::string _name;
	const static int max_size = 4;

    AMateria *_materials[Character::max_size];
    int _length;


private:

};

#endif