/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 00:34:12 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/28 02:01:10 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Harl.hpp"

int	main(int ac, char **av)
{
	// 1. Parameters
	if (ac != 2)
	{
		std::cerr << "Usage: ./harlFilter METHOD\n"
				  << "Available METHODS: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}

	// 2. Instantiate a Harl Object
	Harl	karen;
	karen.filter(av[1]);

	// 3. Success
	return (0);
}