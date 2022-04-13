#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_LEN 8

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

	void AddContact(Contact *c);

private:
	int length;
	Contact *contacts[MAX_LEN];

};

#endif