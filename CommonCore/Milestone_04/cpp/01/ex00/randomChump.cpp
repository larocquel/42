/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:55:03 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/23 23:59:33 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// randomChump.cpp

#include "Zombie.hpp"

// Creates a Zombie statically (Stack), assigns a name, and makes it announce itself.
// The object is automatically destroyed when the function goes out of scope.
void    randomChump(std::string name)
{
    Zombie  zombie(name);

    zombie.announce();
}