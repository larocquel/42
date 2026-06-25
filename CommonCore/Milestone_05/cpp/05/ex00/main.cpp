/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:05:04 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/25 20:15:27 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Bureaucrat.hpp"

int	main()
{
	// 1. Normal Test
	try
	{
		std::cout << "\n1. Normal Test" << std::endl;

		Bureaucrat	normal;

		std::cout << normal << std::endl;

		normal.incrementGrade();
		std::cout << normal << std::endl;

		normal.decrementGrade();
		std::cout << normal << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
	}

	// 2. High Test
	try
	{
		std::cout << "\n2. High Test" << std::endl;

		Bureaucrat	high("High", 0);

		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
	}

	// 3. Low Test
	try
	{
		std::cout << "\n3. Low Test" << std::endl;

		Bureaucrat	low("Low", 151);

		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
	}

	// 4. Increment Test
	try
	{
		std::cout << "\n4. Increment Test" << std::endl;

		Bureaucrat	inc("Inc", 2);

		std::cout << inc << std::endl;
		inc.incrementGrade();

		std::cout << inc << std::endl;
		inc.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
	}

	// 5. Decrement Test
	try
	{
		std::cout << "\n5. Decrement Test" << std::endl;

		Bureaucrat	dec("Dec", 149);

		std::cout << dec << std::endl;
		dec.decrementGrade();

		std::cout << dec << std::endl;
		dec.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
	}

	return (0);
}