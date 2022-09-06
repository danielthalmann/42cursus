#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(MateriaSource &materiasource);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &materiasource);

    virtual void learnMateria(AMateria *mat);
    virtual AMateria* createMateria(std::string const & type);

protected:

	const static int max_size = 2;

    AMateria *_materials[MateriaSource::max_size];
    int _length;


private:


};

#endif