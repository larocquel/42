/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:59 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:01 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm.cpp

#include "PresidentialPardonForm.hpp"

// Default Constructor: Initializes the base AForm with Pardon rules and default target
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Default")
{
	std::cout << "Default Constructor: Presidential" << std::endl;
}

// Copy Constructor: Copies the base AForm and the specific target
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Presidential" << std::endl;
}

// Copy Assignment Operator: Assigns the base values and the target using polymorphism
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Destructor: Cleans up the PresidentialPardon object
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor: PresidentialPardonForm" << std::endl;
}

// Parametrized Constructor: Creates a Pardon form passing fixed grades to base class and a custom target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "Parametrized Constructor: Presidential" << std::endl;
}

// Execute Override: Validates requirements and announces the presidential pardon
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->executeRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}