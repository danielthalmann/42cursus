
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Array.hpp"

int main ( void )
{
	std::srand(std::time(0));

	size_t count = 10;

	Array<int> arr1(count);
	Array<int> arr2;

	for (size_t i = 0; i < count; i++)
	{
		arr1[i] = std::rand();
	}

	std::cout << std::endl << "get array size" << std::endl  << std::endl;

	std::cout << "arr1.size() = " << arr1.size() << std::endl;
	std::cout << "arr2.size() = " << arr2.size() << std::endl;

	std::cout << std::endl << "copy values" << std::endl  << std::endl;

	std::cout << "arr2 = arr1;" << std::endl;
	arr2 = arr1;
	
	std::cout << "arr2.size() = " << arr1.size() << std::endl;

	std::cout << std::endl << "display content of arr1 and arr2" << std::endl  << std::endl;

	for (size_t i = 0; i < count; i++)
	{
		if (arr1[i] == arr2[i])
			std::cout << std::setw(10) << arr1[i] << " == " <<  arr2[i] << std::endl;
		else
			std::cout << std::setw(10) << arr1[i] << " != " <<  arr2[i] << std::endl;
	}

	std::cout << std::endl << "change arr2 " << std::endl  << std::endl;
	for (size_t i = 0; i < count; i++)
	{
		arr2[i] = std::rand();
	}

	for (size_t i = 0; i < count; i++)
	{
		if (arr1[i] == arr2[i])
			std::cout << std::setw(10) << arr1[i] << " == " <<  arr2[i] << std::endl;
		else
			std::cout << std::setw(10) << arr1[i] << " != " <<  arr2[i] << std::endl;
	}

	std::cout << std::endl << "test exception " << std::endl  << std::endl;

	try
	{
		std::cout << arr1[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
