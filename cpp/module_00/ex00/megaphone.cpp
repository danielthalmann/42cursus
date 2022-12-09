/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:03:11 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/13 12:03:17 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

void stringToUpper(std::string &s)
{
	for (int i = 0; i < (int)s.length(); i++)
	{
		s[i] = toupper(s[i]);
	};
}

int main (int argc, char *argv[])
{

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	
	std::string s;

	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << " ";
		s.assign(argv[i]);
		stringToUpper(s);
		std::cout << s;
	}
	
	std::cout << std::endl;
} 
