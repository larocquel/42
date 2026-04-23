/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 03:13:49 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/12 21:03:37 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/*
Program: Megaphone

Objective: Transform every lowercase char into an uppercase char.

Learned concepts:
- <iostream>: input/output stream header required to use cout and endl.
- <cctype>: header required to use the toupper function.
- std::cout << "Hello, World!" << std::endl;
- std (standard): the standard namespace.
- cout (character output): standard output stream.
- endl (end-line): inserts a newline character and flushes the output buffer.
- static_cast<char> instead of (char) cast c manner
*/
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{
			std::cout << static_cast<char>(toupper(av[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
