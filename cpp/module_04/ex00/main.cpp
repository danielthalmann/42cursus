
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testA( void )
{

	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();	

	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();	

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongcat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;
}

int main ( void )
{
	testA();
	return (0);
}
