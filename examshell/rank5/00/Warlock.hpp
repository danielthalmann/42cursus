#ifndef WARLOCK_HPP
#define WARLOCK_HPP

class Warlock {

    Warlock();
    virtual ~Warlock();
    Warlock(const Warlock& other);
    Warlock &operator=(const Warlock& other);

};

#endif