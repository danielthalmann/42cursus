
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "colors.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
bool bsp2( Point const a, Point const b, Point const c, Point const point);

void drawTriangolo(Point const a, Point const b, Point const c)
{
	
	Point m;
	size_t count = (8 * 8);

	for (size_t i = 0; i < count; i++)
	{
		if (i > 0 && (i % 8) == 0)
			std::cout << std::endl;

		m = Point((float)(i % 8) + 1, 7.0 - (float)(i / 8));

		if (m == a)
			std::cout << ANSI_COLOR_CYAN << "A)" << ANSI_COLOR_RESET;
		else if (m == b)
			std::cout << ANSI_COLOR_CYAN << "B)" << ANSI_COLOR_RESET;
		else if (m == c)
			std::cout << ANSI_COLOR_CYAN << "C)" << ANSI_COLOR_RESET;
		else if (bsp(a, b, c, m))
			std::cout << ANSI_COLOR_CYAN << "xx" << ANSI_COLOR_RESET;
		else
			std::cout << ANSI_COLOR_RESET << ". " ;
	}	
	std::cout << std::endl;
	std::cout << std::endl;
	
}


void inTriangolo(Point const a, Point const b, Point const c, Point const m)
{
	std::cout << ANSI_COLOR_RED << "m" << ANSI_COLOR_RESET " is " << m << std::endl;
	std::cout << std::endl;
	if (bsp(a, b, c, m))
		std::cout << ANSI_COLOR_GREEN << "le point [m] est dans le triangle" << ANSI_COLOR_RESET << std::endl << std::endl;
	else
		std::cout << ANSI_COLOR_RED << "le point [m] n'est pas dans le triangle" << ANSI_COLOR_RESET << std::endl << std::endl;
}

void testA( void )
{
	Point const a(2, 3);
	Point const b(4, 6);
	Point const c(7, 1);
	Point m(6, 4);

	std::cout << ANSI_COLOR_RED << "a" << ANSI_COLOR_RESET " is " << a << std::endl;
	std::cout << ANSI_COLOR_RED << "b" << ANSI_COLOR_RESET " is " << b << std::endl;
	std::cout << ANSI_COLOR_RED << "c" << ANSI_COLOR_RESET " is " << c << std::endl;
	std::cout << std::endl;

	drawTriangolo(a, b, c);

	inTriangolo(a, b, c, m);

	m = Point(4, 3);
	inTriangolo(a, b, c, m);

	m = Point(4.5, 1.5);
	inTriangolo(a, b, c, m);

	m = Point(4, 6);
	inTriangolo(a, b, c, m);

}

int main ( void )
{
	
	std::cout << std::endl << std::endl;
 	testA();
	std::cout << std::endl << std::endl;

	return (0);
}
