#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator> // for iterators

template <typename T>
typename T::iterator &easyfind(T &lst, int p2)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "easyfind " << "\x1b[0m" << std::endl;
	#endif

	typename T::iterator ptr;

    for (ptr = lst.begin(); ptr < lst.end(); ptr++)
        if(1)
			return ptr;
	else
		std::cout << "error";

	return ptr;
};


#endif