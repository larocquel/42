/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:20:29 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 00:09:14 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm.cpp
#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Default")
{
	std::cout << "Default Constructor: Presidential" << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Presidential" << std::endl;
}

// Copy Assignment Operator
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor: PresidentialPardonForm" << std::endl;
}

// Parametrized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "Parametrized Constructor: Presidential" << std::endl;
}

// Virtual Pure Method from Base Class (Abstract)
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	// 1. Requirement Check
	executeRequirements(executor);

	// 2. If passed, inform pardon
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}