/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:32 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/25 17:58:44 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanA.hpp

#include "HumanA.hpp"

// Constructor: Uses the Initialization List to assign the name and bind the weapon reference
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

// Destructor: Empty as there is no dynamic memory to free manually
HumanA::~HumanA() {}

// Public Method: Prints the attack message extracting the weapon's type safely
void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}