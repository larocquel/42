/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:06:38 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 18:26:06 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamonTrap.cpp

#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap Default Constructor called for " << this->_name << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy Constructor called, copying from " << other._name << std::endl;
}

// Copy Assignment Operator
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy Assignment Operator called for " << other._name << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << this->_name << std::endl;
}

// Parameterized Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap Parameterized Constructor called for " << this->_name << std::endl;
}

// attack: Overrides with ScavTrap's specific attack
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

// whoAmI: Exclusive DiamondTrap crisis of identity
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " is thinking about his dear GRANDMA " << ClapTrap::_name << " She was a hero!" << std::endl;
}