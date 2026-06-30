/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:18:19 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 16:12:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.cpp

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default Constructor: Initializes a Bureaucrat with default name and lowest grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default Constructor: Bureaucrat" << std::endl;
}

// Copy Constructor: Creates a new Bureaucrat as a copy of another
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy Constructor: Bureaucrat" << std::endl;
}

// Copy Assignment Operator: Copy the grade (mutable value) of one Bureaucrat to another
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

// Destructor: Cleans up the Bureaucrat object upon deletion or going out of scope
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor: Bureaucrat" << std::endl;
}

// Parametrized Constructor: Creates an obj with the parameters passed and validates the grade
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

// Execute Form Method: Attempts to execute a form, catching and printing exceptions if requirements fail
void Bureaucrat::executeAForm(const AForm& aform) const
{
	try
	{
		aform.execute(*this);
		std::cout << this->_name << " executed " << aform.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << aform.getName() << " because " << e.what() << std::endl;
	}
}

// Sign Form Method: Attempts to sign a form, catching and printing exceptions if the grade is too low
void		Bureaucrat::signAForm(AForm& aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << this->_name << " signed " << aform.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
	}
}

// Increment Method: Increases the Bureaucrat's grade (decreases the number), throwing exception if out of bounds
void	Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing Grade" << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

// Decrement Method: Decreases the Bureaucrat's grade (increases the number), throwing exception if out of bounds
void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing Grade" << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

// High Grade Exception: Returns the error message when grade is above 1
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! Maximum is 1.");
}

// Low Grade Exception: Returns the error message when grade is below 150
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! Minimum is 150.");
}

// Insertion Operator Overload: Prints Bureaucrat's details to the standard output stream
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}