
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "easyfind.hpp"

#include <vector> // for vectors

int main ( void )
{
	
	std::vector<int> lst;

	lst.push_back(2);

	easyfind(lst, 5);

	return (0);
}
