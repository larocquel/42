/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:34:59 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/27 22:00:55 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Constructor: Form" << std::endl;
}

// Copy Constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor: Form" << std::endl;
}

// Copy Assignment Operator
Form&	Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

// Destructor
Form::~Form()
{
	std::cout << "Destructor: Form" << std::endl;
}

// Parametrized Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Parametrized Constructor: Form" << std::endl;

	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

// Name Getter
std::string	Form::getName() const
{
	return (_name);
}

// isSigned Getter
bool		Form::getIsSigned() const
{
	return (_isSigned);
}

// GradeisSigned Getter
int			Form::getGradeToSign() const
{
	return (_gradeToSign);
}

// GradeExecute Getter
int			Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Method
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

// High Grade Exception
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

// Low Grade Exception
const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// Override Insert Operator
std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form: " << obj.getName() << " | Signed: " << (obj.getIsSigned() ? "yes" : "no") << " | Grade to sign: " << obj.getGradeToSign() << " | Grade to execute: " << obj.getGradeToExecute();
	return (os);
}
