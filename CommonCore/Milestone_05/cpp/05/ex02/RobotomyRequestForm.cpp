/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:57 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/29 23:36:42 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.cpp

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default")
{
	std::cout << "Default Constructor: Robotomy" << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Robotomy" << std::endl;
}

// Copy Assignment Operator
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor: Robotomy" << std::endl;
}

// Parametrized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "Parametrized Constructor: Robotomy" << std::endl;
}

// Virtual Pure Method from Base Class
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	// 1. Check AForm Requirements
	this->executeRequirements(executor);

	// 2. Make drill noise Robotomize target(50% success rate)
	std::cout << "zzzzzzt, zzzzzzt, zzzzzzt" << std::endl;

	// 2. Robotomize target (50% success rate)
	int	n = rand();

	if (n % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
		printRobot();
	}
	else
	{
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
	}
}

void RobotomyRequestForm::printRobot() const
{
    std::cout << "              ,--.    ,--.\n"
              << "             ((O ))--((O ))\n"
              << "           ,'_`--'____`--'_`.\n"
              << "          _:  ____________  :_\n"
              << "         | | ||::::::::::|| | |\n"
              << "         | | ||::::::::::|| | |\n"
              << "         | | ||::::::::::|| | |\n"
              << "         |_| |/__________\\| |_|\n"
              << "           |________________|\n"
              << "        __..-'            `-..__\n"
              << "     .-| : .----------------. : |-.\n"
              << "   ,\\ || | |\\______________/| | || /.\n"
              << "  /`.\\:| | ||  __  __  __  || | |;/,'\\\n"
              << " :`-._\\;.| || '--''--''--' || |,:/_.-':\n"
              << " |    :  | || .----------. || |  :    |\n"
              << " |    |  | || '----SSt---' || |  |    |\n"
              << " |    |  | ||   _   _   _  || |  |    |\n"
              << " :,--.;  | ||  (_) (_) (_) || |  :,--.;\n"
              << " (`-'|)  | ||______________|| |  (|`-')\n"
              << "  `--'   | |/______________\\| |   `--'\n"
              << "         |____________________|\n"
              << "          `.________________,'\n"
              << "           (_______)(_______)\n"
              << "           (_______)(_______)\n"
              << "           (_______)(_______)\n"
              << "           (_______)(_______)\n"
              << "          |        ||        |\n"
              << "          '--------''--------'\n"
			  << std::endl;
}
