/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:35 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 13:03:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.cpp

#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called for " << this->_name << std::endl;
}

// Copy Constructor: Passes the object to the Base Class copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) // Como um ScavTrap é derivada da Base ClapTrap, todos os valores já ficam inicializados
{
	std::cout << "ScavTrap Copy Constructor called, copying from " << other._name << std::endl;
}

// Copy Assignment Operator: Call the base class assignment operator to handle the attributes
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy Assignment Operator called for " << other._name << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

// Parameterized Constructor: Calls the Base Class parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Parameterized Constructor called for " << this->_name << std::endl;
}

// attack: Overrides the ClapTrap attack with new messages and values
void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap " <<  _name << " Can't VIOLENTLY ATTACK (HP = 0 or Energy = 0)" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name <<  " VIOLENTLY ATTACKS " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// guardGate: Exclusive ScavTrap method
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in GATE KEEPER MODE." << std::endl;
}