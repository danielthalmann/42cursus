#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template < typename  T>
typename T::iterator easyfind(T &lst, int value)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "easyfind " << "\x1b[0m" << std::endl;
	#endif

	typename T::iterator iterator = std::find(lst.begin(), lst.end(), value);

	if (iterator == lst.end())
		throw std::exception();

	return (iterator);
};


#endif