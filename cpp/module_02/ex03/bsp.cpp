#include "Fixed.hpp"
#include "Point.hpp"

/**
 * @brief 
 * 
 * @param a point a du vecteur [ab]
 * @param b point b du vecteur [ab]
 * @param point point autour du vecteur
 * @return Fixed > 0 le point est à gauche du vecteur [ab]
 * 				 = 0 le point est sur le vecteur [ab]
 * 				 < 0 le point est à droite du vecteur [ab]
 */
Fixed isLeft(Point const a, Point const b, Point const point)
{
	return  ( (b.getX() - a.getX()) * (point.getY() - a.getY())
			- (b.getY() - a.getY()) * (point.getX() - a.getX())
	);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void) a;
	(void) b;
	(void) c;
	(void) point;

	Fixed d, e, f;

	d = isLeft(a, c, point); 
	e = isLeft(c, b, point);
	f = isLeft(b, a, point);

	if (d > 0.0f && e > 0.0f && f > 0.0f)
		return (true);
	else
		return (false);
}

