/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:03:22 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 17:04:57 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	// std::cout << std::setiosflags (std::ios::left) << std::setw(20) << "Contact" <<  "Construct" << std::endl;
}

Contact::~Contact()
{
	// std::cout << std::setiosflags (std::ios::left) << std::setw(20) << "Contact" << "Destruct " <<  LastName << " " << FirstName << std::endl;
}

void Contact::setIndex(int n)
{
	index = n;
}

void Contact::setLastName(std::string n)
{
	lastName = n;
}

void Contact::setFirstName(std::string n)
{
	firstName = n;
}

void Contact::setNickName(std::string n)
{
	nickName = n;
}

void Contact::setPhone(std::string n)
{
	phone = n;
}

void Contact::setDarkestSecret(std::string n)
{
	secret = n;
}

std::string Contact::truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width - 3) + "...";
    return str;
}


void Contact::displayList(void)
{
	if (index < 0)
		return ;
	std::cout << std::setiosflags (std::ios::left);
	std::cout << " | ";
	std::cout << std::setiosflags (std::ios::right);
	std::cout << std::setw(10) << index << " | ";
	std::cout << std::setw(10) << truncate(firstName, 10) << " | ";
	std::cout << std::setw(10) << truncate(lastName, 10) << " | ";
	std::cout << std::setw(10) << truncate(nickName, 10) << " | " << std::endl;
}