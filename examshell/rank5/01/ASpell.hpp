#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ASpell {

private:    

public:

    ASpell(const std::string &n = "", const std::string &e = "");
    virtual ~ASpell();
    ASpell(const ASpell& other);
    ASpell &operator=(const ASpell& other);

public:
    const std::string &getName() const;
    const std::string &getEffects() const;
    ASpell *clone() = 0;
    
private:

    std::string name;
    std::string effects;

};

#endif