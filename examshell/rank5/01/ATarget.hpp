#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ATarget {

private:    

public:

    ATarget(const std::string &t = "");
    virtual ~ATarget();
    ATarget(const ATarget& other);
    ATarget &operator=(const ATarget& other);
    virtual ATarget *clone() = 0;

public:
    void getHitBySpell(const ASpell &spell);
    const std::string &getType() const;
<<<<<<< HEAD
    ASpell *clone() const = 0;
=======
>>>>>>> a5ad571ebdd738b087fcb846b24d15881cf0954e
    
private:

    std::string _type;

};

#endif