/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:27:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 22:42:01 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Function: Main entry point of the program, validates arguments and triggers the complaints
int main(int ac, char **av)
{
    // 1. Parameter Check
    if (ac < 2)
    {
        std::cerr << "Usage: ./harlAKAkaren DEBUG INFO WARNING ERROR ..." << std::endl;
        return (1);
    }

    // 2. Instantiate the Harl object
    Harl    karen;

    // 3. Loop through the provided arguments and call the complain method for each
    for (int i = 1; i < ac; i++)
    {
        std::cout << std::endl;
        karen.complain(av[i]);
    }

    // 4. Formatting with nline
    std::cout << std::endl;
    
    return (0);
}