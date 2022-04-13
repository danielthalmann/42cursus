#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
public:
    Contact();
    ~Contact();

	void SetLastName(std::string n);
	void SetFirstName(std::string n);
	static Contact *create();

	static int idx;

private:
	std::string FirstName;
	std::string LastName;
};

#endif