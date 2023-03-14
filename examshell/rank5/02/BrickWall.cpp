#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall")
{

}

BrickWall::~BrickWall()
{

}

BrickWall::BrickWall(const BrickWall &other)
: ATarget(other)
{

}

BrickWall &BrickWall::operator=(const BrickWall &other)
{
    ATarget::operator=(other);
    return *this;
}

ATarget *BrickWall::clone() const
{
    return new BrickWall();
}
