/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:18:54 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/29 02:34:16 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.cpp

#include "AForm.hpp"

// Default Constructor
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Constructor: AForm" << std::endl;
}

// Copy Constructor
AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor: AForm" << std::endl;
}

// Copy Assignment Operator
AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

// Virtual Destructor
AForm::~AForm()
{
	std::cout << "Virtual Destructor: AForm" << std::endl;
}

// Parametrized Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Parametrized Constructor: AForm" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

// Getters
std::string	AForm::getName() const
{
	return (_name);

}

bool		AForm::getIsSigned() const
{
	return (_isSigned);
}

int			AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int			AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Methods
void		AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

// Validation Function
void		AForm::executeRequirements(const Bureaucrat& executor) const
{
	// 1. Not Signed Form can't be executed
	if (_isSigned == false)
	{
		throw AForm::NotSignedException();
	}

	// 2. Not enough grade Executor can't execute
	if (executor.getGrade() > _gradeToExecute)
	{
		throw AForm::GradeTooLowException();
	}
}

// High Grade Exception
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

// Low Grade Exception
const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// Not Signed Exception
const char*	AForm::NotSignedException::what() const throw()
{
	return ("AForm not signed!");
}

// Override Insert Operator
std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm: " << obj.getName() << " | Signed: " << (obj.getIsSigned() ? "yes" : "no") << " | Grade to sign: " << obj.getGradeToSign() << " | Grade to execute: " << obj.getGradeToExecute();
	return (os);
}