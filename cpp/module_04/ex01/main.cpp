
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
		Brain *b = animal[i]->getBrain();
		for(int y = 0; y < 3; y++)
		{
			std::cout << b->getIdeas()[y] << std::endl;
		}
		
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
