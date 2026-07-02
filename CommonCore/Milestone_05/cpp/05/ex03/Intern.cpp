/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:06 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/02 18:19:22 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.cpp

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default Constructor: Intern" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Copy Constructor: Intern" << std::endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor: Intern" << std::endl;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	// 1. Names Array
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	// 2. Pointers Arrays
	AForm*	(Intern::*funcs[3])(const std::string& target) const =
	{
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	// 3. Loop
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcs[i])(formTarget);
		}
	}

	// 4. Error
	std::cout << "Error: Unknown form, try with a valid form" << std::endl;

	return (NULL);
}

AForm*	Intern::makeShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}