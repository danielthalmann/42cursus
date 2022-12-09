/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:04:21 by dthalman          #+#    #+#             */
/*   Updated: 2022/05/11 11:50:57 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>      // std::setw
#include "Contact.hpp"

#define MAX_LEN 8

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

	Contact &getNewContact(void);
	Contact *getContact(int idx);
	void showBook(void);

private:
	int _length;
	Contact _contacts[MAX_LEN];

};

#endif