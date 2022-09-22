#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

class NotFoundException : public std::exception {
   const char * what () const throw () {
      return "Value not found";
   }
};

template < typename T>
typename T::iterator easyfind(T &lst, int value);

std::map<int, int>::iterator easyfind(std::map<int, int> &lst, int value);

#include "easyfind.tpp"

#endif