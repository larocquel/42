/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:35:15 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/27 22:07:15 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n=========================================" << std::endl;
	std::cout << "        TEST 1: THE SUCCESSFUL SIGN        " << std::endl;
	std::cout << "=========================================\n" << std::endl;
	try
	{
		// 1. High Grade Bureaucrat & Form
		Bureaucrat  eneas("Enéas", 2);
		Form        constitution("Constitution", 5, 5);

		// 2. Print initial states
		std::cout << eneas << std::endl;
		std::cout << constitution << std::endl;

		// 3. Enéas Signs Constitution (SUCCESS)
		eneas.signForm(constitution);

		// 4. Test Form SUCCESS (Should be signed: yes)
		std::cout << constitution << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected Error: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "          TEST 2: THE FAILED SIGN          " << std::endl;
	std::cout << "=========================================\n" << std::endl;
	try
	{
		// 1. Low Grade Bureaucrat & Form
		Bureaucrat  lula("Lula", 150);
		Form        constitution("Constitution", 5, 5);

		// 2. Print initial states
		std::cout << lula << std::endl;
		std::cout << constitution << std::endl;

		// 3. Lula Sign Constitution (FAIL)
		lula.signForm(constitution);

		// 4. Test Form FAIL (Should be signed: no)
		std::cout << constitution << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected Error: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "        TEST 3: FORM LIMIT EXCEPTIONS      " << std::endl;
	std::cout << "=========================================\n" << std::endl;

	// Test (< 1)
	try
	{
		std::cout << "Trying to create Form 'Capital' (0, 0)..." << std::endl;
		Form    capital("Capital", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error Caught: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------" << std::endl;

	// Test (> 150)
	try
	{
		std::cout << "Trying to create Form 'Manifesto' (151, 151)..." << std::endl;
		Form    manifesto("Manifesto", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "             END OF TESTS                  " << std::endl;
	std::cout << "=========================================\n" << std::endl;

	return (0);
}