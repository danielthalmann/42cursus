/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:03:22 by dthalman          #+#    #+#             */
/*   Updated: 2022/05/11 12:05:21 by dthalman         ###   ########.fr       */
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
	_index = n;
}

void Contact::setLastName(std::string n)
{
	_lastName = n;
}

void Contact::setFirstName(std::string n)
{
	_firstName = n;
}

void Contact::setNickName(std::string n)
{
	_nickName = n;
}

void Contact::setPhone(std::string n)
{
	_phone = n;
}

void Contact::setDarkestSecret(std::string n)
{
	_secret = n;
}

std::string Contact::truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width - 3) + "...";
    return str;
}

void Contact::displayList(void)
{
	if (_index < 0)
		return ;
	std::cout << std::setiosflags (std::ios::left);
	std::cout << " | ";
	std::cout << std::setiosflags (std::ios::right);
	std::cout << std::setw(10) << _index << " | ";
	std::cout << std::setw(10) << truncate(_firstName, 10) << " | ";
	std::cout << std::setw(10) << truncate(_lastName, 10) << " | ";
	std::cout << std::setw(10) << truncate(_nickName, 10) << " | " << std::endl;
}

void Contact::displayDetail(void)
{
	std::cout << std::setiosflags (std::ios::left);
	std::cout << " index   : " << _index << std::endl;
	std::cout << " prenom  : " << _firstName << std::endl;
	std::cout << " nom     : " << _lastName << std::endl;
	std::cout << " pseudo  : " << _nickName << std::endl;
	std::cout << " tel     : " << _phone << std::endl;
	std::cout << " secret  : " << _secret << std::endl;
}