/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 02:41:45 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 05:32:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLoser.hpp"

int main(int ac, char **av)
{
    // 1. Argument Check
    if (ac != 4)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./dontbesed <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    // 2. Instantiate the object
    SedLoser    SearchAnd(av[1], av[2], av[3]);

    // 3. Execute function and Returns
    return (SearchAnd.replace());
}