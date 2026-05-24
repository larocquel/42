/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 01:07:42 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 03:10:20 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.cpp

#include "Zombie.hpp"

// Constructor: Required to allocate arrays of objects (new Zombie[N])
Zombie::Zombie()
{
	// Left empty on purpose. Initialization happens later via setter.
}

// Setter: Assigns the name and index to the zombie after it is instantiated
void	Zombie::setNameAndIndex(std::string name, int index)
{
	_name = name;
	_index = index;
	std::cout << index << " - " << std::left << std::setw(10) << _name
			  << ": BuaaaaaaaaaaaBuaaaaaaaaaa" << std::endl;
}

// Public Method: Makes the zombie announce itself
void	Zombie::announce(int index)
{
	std::cout << index << " - " << std::left << std::setw(10) << _name
			  << ": Moar BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor: Proves the LIFO (Last-In, First-Out) destruction order
Zombie::~Zombie(void)
{
	std::cout << _index << " - " << std::left << std::setw(10) << _name
			  << ": HeaaaaaaaaaaaadShooooooot" << std::endl;
}
