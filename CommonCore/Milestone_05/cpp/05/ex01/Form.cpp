/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:34:59 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/26 02:04:40 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp

#include "Form.hpp"

// Default Constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Constructor: Default" << std::endl;
}

// Copy Constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Constructor: Copy" << std::endl;
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
	std::cout << "Form Destructor" << std::endl;
}

// Parametrized Constructor
Form::Form(std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Constructor: Parametrized" << std::endl;

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

// Aux Method
bool		Form::isValid(int grade)
{
	return ((_gradeToSign >= 1 && _gradeToSign <= 150) ? true:false);
}

// Method
void	Form::beSigned(Bureaucrat& b)
{
	if (isValid(_gradeToSign) && b.getGrade() <= _gradeToSign)
	{
		std::cout << b.getName() << " signed " << _name << std::endl;
		_isSigned = true;
	}
	else
	{
		throw Form::gradeTooLowException();
	}
}

// High Grade Exception
const char*	Form::GradeTooHighException::what() const throw()
{
}

// Low Grade Exception
const char*	Form::GradeTooLowException::what() const throw()
{
}

// Override Insert Operator
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
}

