/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:09 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/25 17:54:53 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Weapon.cpp

#include "Weapon.hpp"

// Constructor: Uses the Initialization List to set the initial weapon type
Weapon::Weapon(std::string type) : _type(type) {}

// Destructor: Empty as there is no dynamic memory to free manually
Weapon::~Weapon() {}

// Public Method: Setter used to update the weapon's type
void Weapon::setType(std::string type)
{
	_type = type;
}

// Public Method: Getter used to return a constant reference to the weapon's type
const std::string &Weapon::getType(void)
{
	return (_type);
}