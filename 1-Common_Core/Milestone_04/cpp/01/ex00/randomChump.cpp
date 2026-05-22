/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:55:03 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 21:37:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// randomChump.cpp

#include "Zombie.hpp"

// This function creates a zombie, names it, and makes it announce itself.
void 	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}