/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:27:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 21:40:55 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Harl.hpp"

int	main(int ac, std::string av[])
{
	if (ac < 2)
	{
		std::cerr << "Error: Invalid number of parameters" << std::endl;
	}

	for (int i = 0, i < ac, i++)
	{
		Harl::complain(av[i]);
	}
}