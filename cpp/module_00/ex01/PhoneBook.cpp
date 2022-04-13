#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
	length = 0;
	for (size_t i = 0; i < MAX_LEN; i++)
		contacts[i] = 0;
	
	std::cout << "PhoneBook Construct" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destruct" << std::endl;

	for (size_t i = 0; i < MAX_LEN; i++)
		if (contacts[i])
			delete contacts[i];
}

void PhoneBook::AddContact(Contact *c)
{
	std::cout << "AddContact to index : " << length << std::endl;
	
	c->Whoami();

	contacts[length] = c;
	length++;
	length = length % MAX_LEN;

}

