/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:33:10 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/04 16:40:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Default Constructor: Form" << std::endl;
}

// Copy Constructor
Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Copy Constructor: Form" << std::endl;
}

// Copy Assignment Operator
Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Destructor: Form" << std::endl;
}

// Parametrized Constructor
Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Parametrized Constructor: Form" << std::endl;
	if (_signGrade < 1 || _executeGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (_signGrade > 150 || _executeGrade > 150)
	{
		throw GradeTooLowException();
	}
}

// Name Getter
std::string		Form::getName(void) const
{
	return (_name);
}

// isSigned Getter
bool			Form::getIsSigned(void) const
{
	return (_isSigned);
}

// signGrade Getter
int				Form::getSignGrade(void) const
{
	return (_signGrade);
}

// executeGrade Getter
int				Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

// beSigned Function
void			Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_signGrade)
	{
		this->_isSigned = true;
	}
	else
	{
		throw (GradeTooLowException());
	}
}

// Exceptions

// High Grade
const char*		Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High.");
}

// Low Grade
const char*		Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low.");
}

// Overload Insertion Operator
std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form: " << obj.getName() << " | Signed: " << (obj.getIsSigned() ? "yes" : "no") << " | Grade to sign: " << obj.getSignGrade() << " | Grade to execute: " << obj.getExecuteGrade();
	return (os);
}