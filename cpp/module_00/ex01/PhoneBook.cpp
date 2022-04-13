/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:04:05 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 17:05:54 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
	length = 0;
	for (size_t i = 0; i < MAX_LEN; i++)
	{
		contacts[i].setIndex(-1);
	}
	// std::cout << std::setiosflags (std::ios::left) << std::setw(20) << "PhoneBook" <<  "Construct" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << std::setiosflags (std::ios::left) << std::setw(20) << "PhoneBook" <<  "Destruct" << std::endl;
}

Contact &PhoneBook::getNewContact(void)
{
	Contact &c = contacts[length];
	c.setIndex(length);
	std::cout << length;
	length = ++length % MAX_LEN;
	return (c);
}

void PhoneBook::showBook(void)
{
	std::cout << std::setiosflags (std::ios::left);
	std::cout << " " << std::setfill('-') << std::setw(53) << "-" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setiosflags (std::ios::right);
	std::cout << " | ";
	std::cout << "     index | ";
	std::cout << "        fn | ";
	std::cout << "        ln | ";
	std::cout << "        nn | " << std::endl;
	std::cout << " " << std::setfill('-') << std::setw(53) << "-" << std::endl;
	std::cout << std::setfill(' ');
	
	for (size_t i = 0; i < MAX_LEN; i++)
	{
		contacts[i].displayList();
	}
	std::cout << " " << std::setfill('-') << std::setw(53) << "-" << std::endl;
	std::cout << std::setfill(' ');
}