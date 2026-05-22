/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:46:07 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 21:36:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie = newZombie("Heappy");
	zombie->announce();
	delete zombie;

	randomChump("Stan CK");
}