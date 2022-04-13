/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:03:45 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 17:04:51 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>      // std::setw

class Contact
{
public:
    Contact();
    ~Contact();

	void setLastName(std::string n);
	void setFirstName(std::string n);
	void setNickName(std::string n);
	void setPhone(std::string n);
	void setDarkestSecret(std::string n);
	void setIndex(int n);
	void displayList(void);

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string secret;
	int index;

	std::string truncate(std::string str, size_t width);
};

#endif