#ifndef POINT_HPP
#define POINT_HP

#include <iostream>
#include "Fixed.hpp"
#include "colors.hpp"

class Point
{
public:
    Point();
    Point(const Point& Point);
    Point(const float x, const float y);
    Point(const Fixed x, const Fixed y);
    ~Point();

    Point &operator=(const Point& point);

    Fixed getX() const;
    Fixed getY() const;

private:
    Fixed _x;
    Fixed _y;
};

std::ostream &operator<<(std::ostream &out, Point const &value);

#endif