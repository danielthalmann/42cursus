
#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "Atarget.hpp"

class BrickWall : public ATarget
{

public:
    BrickWall();
    ~BrickWall();
    BrickWall(const BrickWall &other);
    BrickWall &operator=(const BrickWall &other);

public:
    ATarget *clone() const;

};

#endif
