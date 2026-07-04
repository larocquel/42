/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:01:28 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/03 21:05:20 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.cpp

#include "Bureaucrat.hpp"

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

// Copy Assgnment Operator
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor: Bureaucrat" << std::endl;
}

// Parametrized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Parametrized Constructor: Bureaucrat" << std::endl;
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	_grade = grade;
}

// Name Getter
std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

// Grade Getter
int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// Increment Method
void		Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 >= 1)
		_grade--;
	else
		throw GradeTooHighException();
}

// Decrement Method
void		Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 <= 150)
		_grade++;
	else
		throw GradeTooLowException();
}

// High Grade Exception
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

// Low Grade Exception
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

// Overload Insertion
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}