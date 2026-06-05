/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:50:21 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 13:09:33 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FragTrap.cpp

#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called for " << this->_name << std::endl;
}

// Copy Constructor: Passes the object to the Base Class copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) // Como um FragTrap é derivada da Base ClapTrap, todos os valores já ficam inicializados
{
	std::cout << "FragTrap Copy Constructor called, copying from " << other._name << std::endl;
}

// Copy Assignment Operator: Call the base class assignment operator to handle the attributes
FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy Assignment Operator called for " << other._name << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

// Parameterized Constructor: Calls the Base Class parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Parameterized Constructor called for " << this->_name << std::endl;
}

// attack: Overrides the ClapTrap attack with new messages and values
void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "FragTrap " <<  _name << " Can't OBLITERATED ATTACK (HP = 0 or Energy = 0)" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name <<  " OBLITERATED ATTACKS " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// highFivesGuys: Exclusive FragTrap method
void	FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
        std::cout << "FragTrap " << _name << " is dead and can't high five anyone..." << std::endl;
    else
        std::cout << "FragTrap " << _name << " requests a legendary HIGH FIVE! ✋" << std::endl;
}