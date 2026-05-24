/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 01:08:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 03:11:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// zombieHorde.cpp

#include "Zombie.hpp"

// Allocates N zombies in a single contiguous memory block and initializes them
Zombie* zombieHorde(int N, std::string name)
{
	// Allocating the array on the heap
	Zombie	*zombies = new Zombie[N];

	// Initializing each zombie's state
	for(int index = 0; index < N; index++)
	{
		zombies[index].setNameAndIndex(name, index);
	}
	std::cout << std::endl;

	return (zombies);
}