/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:03:53 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 17:09:43 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

void stringToUpper(std::string &s);

int main ()
{
	std::string input;
	std::string buffer;
	std::string index;
	PhoneBook book;

	std::cout << std::endl << "PhoneBook est à ton service." << std::endl << std::endl;
	while (1)
	{
		
		std::cout << "les commandes suivantes sont à ta disposition :" << std::endl;
		std::cout << std::setiosflags (std::ios::left);
		std::cout << std::setw(10) << "ADD" << ": enregistrer un nouveau contact" << std::endl;
		std::cout << std::setw(10) << "SEARCH" << ": affiche le contact demandé" << std::endl;
		std::cout << std::setw(10) << "EXIT" << ": Le programme quitte et les contacts sont perdus à jamais !" << std::endl;
		
		std::cout << std::endl << std::endl << "Donne moi tes ordres $ ";
		std::getline(std::cin, input);
		
		stringToUpper(input);

		if (input == "ADD")
		{
			std::cout << std::endl << "Je vais ajouter un nouveau contact. Merci de renseigner les valeurs suivantes :" << std::endl;
			Contact &contact = book.getNewContact();
			std::cout << std::endl << "Peux-tu saisir le prénom ? ";
			std::getline(std::cin, buffer);
			contact.setFirstName(buffer);
			std::cout << std::endl << "Peux-tu saisir le nom ? ";
			std::getline(std::cin, buffer);
			contact.setLastName(buffer);
			std::cout << std::endl << "Peux-tu saisir le surnom ? ";
			std::getline(std::cin, buffer);
			contact.setNickName(buffer);
			std::cout << std::endl << "Peux-tu saisir le numéro de téléphone ? ";
			std::getline(std::cin, buffer);
			contact.setPhone(buffer);
			std::cout << std::endl << "Peux-tu me dire quel secret terrible cette personne cache ? ";
			std::getline(std::cin, buffer);
			contact.setDarkestSecret(buffer);
			std::cout << std::endl << std::endl;

		} 
		else if (input == "SEARCH") 
		{
			book.showBook();

			std::cout << std::endl << "Qui recherches-tu ? ";
			std::getline(std::cin, index);
			std::cout << std::endl << std::endl;

		}
		else if (input == "EXIT")
		{
			std::cout << std::endl << "Bye." << std::endl;
			std::cout << std::endl << std::endl;
			return (0);
		}
		else
		{
			std::cout << std::endl << "Ta commande n'est pas reconnue." << std::endl << std::endl;
		}

	}

	return (0);
}

void stringToUpper(std::string &s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		s[i] = toupper(s[i]);
	};
}
