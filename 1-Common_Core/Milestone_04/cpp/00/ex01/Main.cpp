/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:55:05 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/28 02:19:19 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	object;
	std::string	command;

	while (command != "EXIT")
	{
		std::cout << "Type a command (ADD, SEARCH or EXIT):" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			object.add();
		else if (command == "SEARCH")
			object.search();
		else if (command != "EXIT")
			std::cout << "Invalid command" << std::endl;
	}
	std::cout << "Goodbye 👋" << std::endl;
	return (0);
}