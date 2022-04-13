#include "Contact.hpp"

int Contact::idx = 0;

Contact::Contact()
{
	std::cout << "Contact Construct" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact Destruct" << std::endl;
}

void Contact::SetLastName(std::string n)
{
	LastName = n;
}

void Contact::SetFirstName(std::string n)
{
	FirstName = n;
}

Contact *Contact::create(void)
{
	std::string firstname[5] = {"Vincent", "Céline", "Christophe", "Kenza", "Jérémie"};
	std::string lastname[4] = {"Blaise", "Stroustrup", "Pascal", "Gates"};
	Contact *c = new Contact();
	c->SetFirstName( firstname[Contact::idx % 5]);
	c->SetLastName( lastname[Contact::idx % 4] );
	Contact::idx++;
	return (c);
}

void Contact::Whoami(void)
{
	std::cout << LastName << " " << FirstName << std::endl;
}