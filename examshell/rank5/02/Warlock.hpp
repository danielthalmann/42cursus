#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {

private:    
    Warlock();


public:

    Warlock(const std::string &n, const std::string &t);
    virtual ~Warlock();
    Warlock(const Warlock& other);
    Warlock &operator=(const Warlock& other);

public:
    const std::string &getTitle() const;
    const std::string &getName() const;
    void setTitle(const std::string &t);
    void introduce() const;
  
    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string &s);
    void launchSpell(const std::string &s, ATarget &target);

    
private:

    std::string _name;
    std::string _title;

    SpellBook _book;


    std::map<std::string, ASpell*> _spells;


};

#endif