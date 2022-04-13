/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:04:21 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 16:42:07 by dthalman         ###   ########.fr       */
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
	void showBook(void);

private:
	int length;
	Contact contacts[MAX_LEN];

};

#endif