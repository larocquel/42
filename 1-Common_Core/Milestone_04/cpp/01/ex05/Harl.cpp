/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:24:28 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 22:41:00 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor: Default initialization
Harl::Harl() {}

// Destructor: Default cleanup
Harl::~Harl() {}

// Private Method: Prints a debug level message
void    Harl::debug(void)
{
    std::cout << "DEBUG: " << "I love to remove the sauce of my francesinha, I really do." << std::endl;
}

// Private Method: Prints an info level message
void    Harl::info(void)
{
    std::cout << "INFO: " << "I’d appreciate a flat Sagres for not eating francesinha with sauce!" << std::endl;
}

// Private Method: Prints a warning level message
void    Harl::warning(void)
{
    std::cout << "WARNING: " << "Do I need cutlery to eat a sandwich? Come on!" << std::endl;
}

// Private Method: Prints an error level message
void    Harl::error(void)
{
    std::cout << "ERROR: " << "The chef dipped my head in the pan of sauce, I can't stand piripiri!" << std::endl;
}

// Public Method: Executes the matching function to level using Pointers to Member Functions
void    Harl::complain(std::string level)
{
    // 1. Array of strings containing the valid level names
    std::string functionName[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // 2. Array of pointers to member functions corresponding to each level
    void (Harl::*functionPointer[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // 3. Execution loop to find and trigger the requested complaint level
    for (int i = 0; i < 4; i++)
    {
        if (level == functionName[i])
        {
            // Execute the matched member function via the pointer
            (this->*functionPointer[i])();
            return ;
        }
    }

    // 4. Generic error message if the provided level is not found
    std::cerr << "FDS: " << level << "? Unacceptable, GET OUT!" << std::endl;
}