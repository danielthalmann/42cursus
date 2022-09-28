
#include <list>
#include "MutantStack.hpp"

template <class T>
void test (T &mstack)
{
	mstack.push(5);
	mstack.push(17);

	std::cout << "top()  : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size() : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	typename T::iterator it = mstack.begin();
	typename T::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	T s(mstack);
}


void test (std::list<int> &mstack)
{
	mstack.push_back(5);
	mstack.push_back(17);


	std::cout << "top()  : " << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << "size() : " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);
}


int main()
{

	MutantStack<int> mstack;
	test(mstack);

	std::list<int> mlist;
	test(mlist);

	return 0;
}
