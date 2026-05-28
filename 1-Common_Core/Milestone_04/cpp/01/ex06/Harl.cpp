/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 00:34:58 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/28 02:13:26 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.cpp

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug(void)
{
    std::cout << "[DEBUG]\n" << "Contain contextual information. Mostly used for problem diagnosis.\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]\n" << "Contain extensive information. Helpful for tracing program execution in a production environment.\n" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]\n" << "Indicate a potential issue in the system. It can be handled or ignored.\n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]\n" << "Indicate that an unrecoverable error has occurred. Usually a critical issue.\n" << std::endl;
}

void    Harl::filter(std::string level)
{
    // 1. Array to transform strinf in a number
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         levelIndex = -1;  // -1 for error

    // 2. Search for the string
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            levelIndex = i;
            break;
        }
    }

    // 3. Switch case with fall through
    switch (levelIndex)
    {
        case 0:
        {
            this->debug();
        }
        // fall through
        case 1:
        {
            this->info();
        }
        // fall through
        case 2:
        {
            this->warning();
        }
        // fall through
        case 3:
        {
            this->error();
            break;
        }
        default:
        {
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
    }
}