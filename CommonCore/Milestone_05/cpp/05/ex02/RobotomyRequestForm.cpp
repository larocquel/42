/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:57 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 16:56:44 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.cpp

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Default Constructor: Initializes the base AForm with Robotomy rules and default target
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default")
{
	std::cout << "Default Constructor: Robotomy" << std::endl;
}

// Copy Constructor: Copies the base AForm and the specific target
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Robotomy" << std::endl;
}

// Copy Assignment Operator: Assigns the base values and the target using polymorphism
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Destructor: Cleans up the Robotomy object
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor: Robotomy" << std::endl;
}

// Parametrized Constructor: Creates a Robotomy form passing fixed grades to base class and a custom target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "Parametrized Constructor: Robotomy" << std::endl;
}

// Execute Override: Validates requirements and attempts a 50% chance robotomy
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->executeRequirements(executor);
	std::cout << "DRILL NOISE: ZZZZZZZT, ZZZZZZZT, ZZZZZZZT, ZZZZZZZT" << std::endl;

	int	sec = std::time(NULL);
	if (sec % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
		printRobot();
	}
	else
	{
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
	}
}

// Print Robot Method: Prints an ASCII robot representation
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
			  << "          '--------''--------'\n" << std::endl;
}
