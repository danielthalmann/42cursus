#include "Point.hpp"

Point::Point() :
	_x (Fixed()),
	_y (Fixed())
{

}

Point::~Point()
{

}

Point::Point(const Point& Point)
{
	_x = Point._x;
	_y = Point._y;
}

Point::Point(const float x, const float y) :
	_x (Fixed(x)),
	_y (Fixed(y))
{

}

Point::Point(const Fixed x, const Fixed y) :
	_x (x),
	_y (y)
{

}

Point &Point::operator=(const Point& point)
{
	_x = point._x;
	_y = point._y;
	return (*this);
}

bool Point::operator==(const Point& point) const
{
	if (this->_x == point._x && this->_y == point._y)
		return true;
	else
		return false;
}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

std::ostream &operator<<(std::ostream &out, Point const &value)
{
	out << ANSI_COLOR_CYAN << "{" <<  ANSI_COLOR_BLUE << value.getX()
	    << ANSI_COLOR_CYAN << "," <<  ANSI_COLOR_BLUE << value.getY()
		<< ANSI_COLOR_CYAN << "}";
	return (out);
}

