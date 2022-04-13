
#include "PhoneBook.hpp"

int main ()
{
	Contact c;
	c.SetFirstName("Daniel");
	c.SetLastName("Thalmann");

	PhoneBook book;
	book.AddContact(Contact::create());

	return (0);
}
