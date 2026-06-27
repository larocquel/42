/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:33:27 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/27 20:07:14 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.cpp

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default Constructor: Bureaucrat" << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy Constructor: Bureaucrat" << std::endl;
}

// Copy Operator
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor: Bureaucrat" << std::endl;
}

// Parametrized Constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Parametrized Constructor: Bureaucrat" << std::endl;

	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

// Name Getter
std::string	Bureaucrat::getName() const
{
	return (_name);
}

// Grade Getter
int			Bureaucrat::getGrade() const
{
	return (_grade);
}

// Increment Method
void	Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing Grade" << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

// Decrement Method
void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing Grade" << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

// Sign Method
void		Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// High Grade Exception
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! Maximum is 1.");
}

// Low Grade Exception
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! Minimum is 150.");
}

// Override Insert Operator
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}