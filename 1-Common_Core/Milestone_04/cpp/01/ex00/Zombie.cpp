/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:55:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 01:23:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.cpp

#include "Zombie.hpp"

// Constructor: Initializes the zombie's name upon instantiation
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << std::left << std::setw(10) << _name << ": Was Born!"  << std::endl;
}

// Public Method: Makes the zombie announce itself
void    Zombie::announce(void)
{
    std::cout << std::left << std::setw(10) << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor: Automatically called upon object destruction (out of scope or deleted)
Zombie::~Zombie()
{
    std::cout << std::left << std::setw(10) << _name << ": Died!" << std::endl;
}