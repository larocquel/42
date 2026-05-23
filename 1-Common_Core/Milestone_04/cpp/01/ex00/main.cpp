/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:46:07 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 00:01:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Zombie.hpp"

int main(void)
{
    // Heap allocation
    Zombie  *zombie = newZombie("Heappy");
    zombie->announce();
    delete zombie;

    // Stack allocation
    randomChump("Stan CK");

    return (0);
}