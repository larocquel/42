/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:24:28 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 21:31:09 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.cpp

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love to remove the sauce of my francesinha, I really do." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe the chef dipped my head in the pan of sauce. It was kinda hot tbh!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I believe I deserve a flat Sagres for not eating francesinha with sauce. Do I need cutllery to eat a sandwish, come on!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unaceptable, just because I used a Benfica shirt on São João. I need to speak with the major NOW!" << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level)
{
	// 1. Array de string com os 4 léveis
	std::string	functions[] = {DEBUG, INFO, WARNING, ERROR};

	// 2. Array de ponteiros para as funções
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// 3. Loop de execução
	for (int i = 0; i < 4; i++)
	{
		if (level == functions[i]) // Posso usar esse if?
		{
			*functions[i];
			return ;
		}
	}
	return ;
}
