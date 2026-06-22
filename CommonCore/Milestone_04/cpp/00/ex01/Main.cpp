/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:55:05 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/05 06:37:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	object;
	std::string	cmd;

	while (cmd != "EXIT")
	{
		std::cout << "\nType a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting..." << std::endl;
			exit(0);
		}
		std::cout << "\n";
		if (cmd == "ADD")
			object.add();
		else if (cmd == "SEARCH")
			object.search();
		else if (cmd != "EXIT")
			std::cout << "Error: Invalid command. Try again!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return (0);
}