
#include <iostream>
#include <cstdlib>
#include <ctime>
	
#include "iter.hpp"

void f1 (int &i)
{
	std::cout << "iter value of i : " << i << std::endl;
}

void f2 (std::string &s)
{
	std::cout << "iter value of s : " << s << std::endl;
}

template <typename T>
void f3 (T &t)
{
	std::cout << "iter value of s : " << t << std::endl;
}

void testA(void)
{
	int is[5];

	for (size_t i = 0; i < 5; i++)
	{
		is[i] =  std::rand();
		std::cout << "value of i init : " << is[i] << std::endl;
	}
	
	iter (is, 5, f1);
}

void testB(void)
{
	std::string s[3];

	s[0] = "test A";
	s[1] = "test B";
	s[2] = "test C";

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "value of s init : " << s[i] << std::endl;
	}

	iter (s, 3, f2);
}


void testC(void)
{
	float f[5];

	for (size_t i = 0; i < 5; i++)
	{
		f[i] =  std::rand() / 1000;
		std::cout << "value of i init : " << f[i] << std::endl;
	}
	
	iter (f, 5, f3);
}


int main ( void )
{
	std::srand(std::time(0));

	testA();
	testB();
	testC();
	return (0);
}
