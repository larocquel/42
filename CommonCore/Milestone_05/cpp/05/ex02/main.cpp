/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:17:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 16:57:20 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "\n--- 1. CREATING FORMS ---" << std::endl;
	ShrubberyCreationForm   greenWorld("PlantTrees");
	RobotomyRequestForm     robotWorld("RobotFactory");
	PresidentialPardonForm  fairWorld("FreeTaxes");

	std::cout << "\n--- 2. LOW GRADE BUREAUCRAT ---" << std::endl;
	Bureaucrat  karl("Marx", 150);

	karl.signAForm(greenWorld);
	karl.signAForm(robotWorld);
	karl.signAForm(fairWorld);

	std::cout << "\n--- 3. UNSIGNED FORM EXECUTION ATTEMPT ---" << std::endl;
	karl.executeAForm(greenWorld);
	karl.executeAForm(robotWorld);
	karl.executeAForm(fairWorld);

	std::cout << "\n--- 4. HIGH GRADE BUREAUCRAT ---" << std::endl;
	Bureaucrat  adam("Smith", 1);

	adam.signAForm(greenWorld);
	adam.signAForm(robotWorld);
	adam.signAForm(fairWorld);

	std::cout << "\n--- 5. SIGNED FORM EXECUTION ---" << std::endl;
	adam.executeAForm(greenWorld);
	adam.executeAForm(robotWorld);
	adam.executeAForm(fairWorld);

	std::cout << "\n--- CLEANUP ---" << std::endl;
	return (0);
}