#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {

public:

    ASpell(const std::string &n = "", const std::string &e = "");
    virtual ~ASpell();
    ASpell(const ASpell& other);
    ASpell &operator=(const ASpell& other);

public:
    const std::string &getName() const;
    const std::string &getEffects() const;
    void launch(ATarget &target);
    virtual ASpell *clone() const = 0;
    
private:

    std::string name;
    std::string effects;

};

#endif