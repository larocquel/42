/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:54 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/25 18:00:23 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanB.cpp

#include "HumanB.hpp"

// Constructor: Uses the Initialization List to assign the name and sets the weapon pointer to NULL
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

// Destructor: Empty as there is no dynamic memory to free manually
HumanB::~HumanB() {}

// Public Method: Prints the attack message, ensuring the pointer is not NULL to avoid Segfaults
void HumanB::attack()
{
	if (!_weapon)
	{
		std::cout << _name << "is unarmed, he's now running AF!" << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

// Public Method: Setter used to extract the memory address of the provided weapon reference and store it
void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}