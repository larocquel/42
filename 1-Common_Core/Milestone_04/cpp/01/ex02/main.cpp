/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:20:27 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 17:30:43 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int	main()
{
	// 1 - Content
	std::string	original = "HI THIS IS BRAIN";
	std::string	*stringPTR = &original;
	std::string	&stringREF = original;

	// 2 - Print Address
	std::cout << "ADDRESS" << std::endl;

	std::cout << std::setw(10) << "Original" << ": " << &original << std::endl;

	std::cout << std::setw(10) << "Pointer" << ": " << stringPTR << std::endl;

	std::cout << std::setw(10) << "Reference" << ": " << &stringREF << "\n" << std::endl;


	// 3 - Print Value
	std::cout << "VALUE" << std::endl;

	std::cout << std::setw(10) << "Original" << ": " << original << std::endl;

	std::cout << std::setw(10) << "Pointer" << ": " << *stringPTR << std::endl;

	std::cout << std::setw(10) << "Reference" << ": " << stringREF << std::endl;
}

/*
** -----------------------------------------------------------------------------
** POINTER vs REFERENCE in C++
** -----------------------------------------------------------------------------
**
** POINTER (*):
** - It is a distinct variable in memory that stores a memory address.
** - Can be declared without initialization, set to NULL, or reassigned to
** point to a different variable later.
** - Requires the dereference operator (*) to access or modify the actual value.
**
** REFERENCE (&):
** - It is merely an alias (another name) for an already existing variable.
** It does not occupy its own distinct space in memory like a pointer does.
** - MUST be initialized immediately upon declaration.
** - Cannot be reassigned to alias a different variable once initialized.
** - Cannot be NULL.
** - Can be accessed directly, exactly like a normal variable, without needing
** any special operators.
** -----------------------------------------------------------------------------
*/