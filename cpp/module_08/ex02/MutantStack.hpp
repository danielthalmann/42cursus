#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack < T >
{
public:
//	virtual ~MutantStack<T>() {};

 	typename std::stack<T>::iterator iterator;

	iterator begin () { return c.begin(); };
	iterator end () { return c.end(); };

};

#endif