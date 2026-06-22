/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:54:55 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/23 23:59:20 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// newZombie.cpp

#include "Zombie.hpp"

// Creates a Zombie dynamically (Heap), assigns a name, and returns its pointer.
// The caller is responsible for freeing the allocated memory.
Zombie* newZombie(std::string name)
{
    Zombie  *zombie = new Zombie(name);

    return (zombie);
}