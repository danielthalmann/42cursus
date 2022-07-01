#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include "colors.hpp"

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& clapTrap);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap& clapTrap);

	void info(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:


	/**
	 * @brief Nom du clap
	 * 
	 */
	std::string _name;
	
	/**
	 * @brief point de vie
	 * 
	 */
	int _hit;
	
	/**
	 * @brief point d'energie  
	 * 
	 */
	int _energy;

	/**
	 * @brief point d'attaque
	 * 
	 */
	int _damage;

};

#endif