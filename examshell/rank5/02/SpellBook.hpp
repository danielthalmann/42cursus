#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "ASpell.hpp"
#include <map>
#include <string>

class SpellBook {

private:



public:
    SpellBook() {}
    ~SpellBook() 
    {
        free();
    }

    void learnSpell(ASpell* spell)
    {
        try {
            _spells.at(spell->getName());
        } catch (...)
        {
            _spells[spell->getName()] = spell->clone();
        }
    }
    
    void forgetSpell(std::string const &spellname)
    {
        _spells.erase(spellname);
    }

    ASpell* createSpell(std::string const &spellname)
    {
        return _spells.at(spellname);
    }

    void free()
    {
        for(std::map<std::string, ASpell*>::const_iterator i = _spells.begin(); i != _spells.end(); i++)
            delete i->second;

        _spells.clear();
    }


private:
    std::map<std::string, ASpell*> _spells;

};


#endif
