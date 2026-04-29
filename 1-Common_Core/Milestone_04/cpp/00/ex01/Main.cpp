/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 02:55:05 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/29 01:45:21 by leoaguia         ###   ########.fr       */
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
		std::cout << "\n";
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
		if (cmd == "ADD")
			object.add();
		else if (cmd == "SEARCH")
			object.search();
		else if (cmd != "EXIT")
			std::cout << "Error: Invalid command. Try again!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl; // Dúvida: Utilizei muitos std::endl no meu código, mas pelo que vi no manual é comum utilizar de forma errada acabando fazendo uma má gestão do buffer, não entendi, será que a minha foi a melhor abordagem?
	return (0);
}