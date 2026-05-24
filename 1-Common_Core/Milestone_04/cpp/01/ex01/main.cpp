/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 01:07:19 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 03:12:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Zombie.hpp"

int	main(void)
{
	// 1. Create the horde
	int		N = 6;
	Zombie	*zombies = zombieHorde(N, "Zé");

	// 2. Test the horde (prove they are alive and well)
	for(int index = 0; index < N; index++)
	{
		zombies[index].announce(index);
	}
	std::cout << std::endl;

	// 3. Clean up the memory using delete[] (mandatory for arrays)
	delete[] zombies;
}