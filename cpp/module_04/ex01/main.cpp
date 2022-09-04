
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_SIZE 4

void testA( void )
{

	Animal *animal[ANIMAL_SIZE];

	for (int i = 0; i < (ANIMAL_SIZE / 2); i++)
		animal[i] = new Dog();

	for (int i = (ANIMAL_SIZE / 2); i < ANIMAL_SIZE; i++)
		animal[i] = new Cat();

	for (int i = 0; i < ANIMAL_SIZE; i++) {
		animal[i]->makeSound();
		
	}


	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_SIZE; i++)
		delete animal[i];
}

int main ( void )
{
	testA();
	return (0);
}
