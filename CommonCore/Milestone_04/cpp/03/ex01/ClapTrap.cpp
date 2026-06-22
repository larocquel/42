/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:03 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 11:16:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.cpp

#include "ClapTrap.hpp"

// Default Constructor: Initializes a ClapTrap with default values.
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called for " << this->_name << std::endl;
}


// Copy Constructor: Creates a new object as a copy of an existing one.
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy Constructor called, copying from " << other._name << std::endl;
}

// Copy Assignment Operator: Takes values from one object to another  existing object.
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Assignment Operator called for " << other._name << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

// Destructor: Called when the object is destroyed (goes out of scope or is deleted).
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
}

// Parameterized Constructor: Initializes a ClapTrap with a specific name.
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Parameterized Constructor called for " << this->_name << std::endl;
}

// --- Mandatory Methods ---

// attack: Costs 1 energy point. Deals damage equal to _attackDamage.
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " <<  _name << " Can't ATTACK (HP = 0 or Energy = 0)" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name <<  " ATTACKS " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// takeDamage: Reduces _hitPoints by amount. Prevents health from dropping below 0.
void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= (int) amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " was DAMAGED. -" << amount << " HP!" << std::endl;
}

// beRepaired: Costs 1 energy point. Restores _hitPoints by amount.
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " <<  _name << " Can't REPAIR (HP = 0 or Energy = 0)" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += (int) amount;
	std::cout << "ClapTrap " << _name << " REPAIRED " << amount << " HP!" << std::endl;
}