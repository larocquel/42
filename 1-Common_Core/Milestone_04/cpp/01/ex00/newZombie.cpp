/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:54:55 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 21:36:39 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// newZombie.cpp

#include "Zombie.hpp"

// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
Zombie* newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);

	return (zombie);
}