/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:35 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 11:52:44 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.cpp

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called for " << this->_name << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) // Como um ScavTrap é derivada da Base ClapTrap, todos os valores já ficam inicializados
{
	std::cout << "ScavTrap Copy Constructor called, copying from " << other._name << std::endl;
}

// Copy Assignment Operator
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
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

// Parametrized Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Parameterized Constructor called for " << this->_name << std::endl;
}

// Override
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

// Exclusive method
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in GATE KEEPER MODE." << std::endl;
}