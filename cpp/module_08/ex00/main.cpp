
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "easyfind.hpp"

#include <vector>
#include <list>
#include <map>

template <class T>
void test (T &vect, int find)
{
	try {
		std::cout << "search of " << find << ", ";
		typename T::iterator found = easyfind(vect, find);
		std::cout << "value " << *found << " founded" << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test (std::map<int, int> &vect, int find)
{
	try {
		std::cout << "search of " << find << ", ";
		std::map<int, int>::iterator found = easyfind(vect, find);
		std::cout << "value " << found->first << " = " << found->second << " founded" << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main ( void )
{
	
	std::vector<int> vect;
	vect.push_back(2);
	vect.push_back(4);
	vect.push_back(24);

	std::cout << std::endl;

	test (vect, 5);
	test (vect, 24);

	std::list<int> lst;
	lst.push_back(2);
	lst.push_back(4);
	lst.push_back(24);

	std::cout << std::endl;

	test (vect, 5);
	test (lst, 24);

	std::map<int, int> mp;
	
	mp[0] = 2;
	mp[1] = 5;
	mp[3] = 25;

	std::cout << std::endl;

	test (mp, 24);
	test (mp, 25);

	return (0);
}
