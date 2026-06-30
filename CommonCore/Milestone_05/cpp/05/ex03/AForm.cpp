/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:25:29 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 17:25:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.cpp

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor: Initializes an abstract AForm with default values
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Constructor: AForm" << std::endl;
}

// Copy Constructor: Creates a new AForm as a copy of another
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor: AForm" << std::endl;
}

// Copy Assignment Operator: Assigns the isSigned of one AForm to another
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

// Virtual Destructor: Ensures derived classes are properly destroyed before the base class
AForm::~AForm()
{
	std::cout << "Virtual Destructor: AForm" << std::endl;
}

// Parametrized Constructor: Creates an abstract object checking if grade limits are respected
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

// Name Getter: Returns name
std::string AForm::getName() const { return (_name); }

// IsSigned Getter: Returns isSigned
bool AForm::getIsSigned() const { return (_isSigned); }

// GradeToSign Getter: Returns the required grade to sign the form
int AForm::getGradeToSign() const { return (_gradeToSign); }

// GradeToExecute Getter: Returns the required grade to execute the form
int AForm::getGradeToExecute() const { return (_gradeToExecute); }

// beSigned Method: Signs the form if the Bureaucrat's grade is high enough, otherwise throws an exception
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

// Validation Function: Centralizes the checking of execution rules before allowing derived forms to act
void AForm::executeRequirements(const Bureaucrat& executor) const
{
	if (_isSigned == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

// High Grade Exception: Returns error message for high grade
const char* AForm::GradeTooHighException::what() const throw() { return ("Grade is too high!"); }

// Low Grade Exception: Returns error message for low grade
const char* AForm::GradeTooLowException::what() const throw() { return ("Grade is too low!"); }

// Not Signed Exception: Returns error message when trying to execute an unsigned form
const char* AForm::NotSignedException::what() const throw() { return ("Form is not signed!"); }

// Insertion Operator Overload: Prints all AForm's attributes to the standard output stream
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "AForm: " << obj.getName() << " | Signed: " << (obj.getIsSigned() ? "yes" : "no")
	   << " | Grade to sign: " << obj.getGradeToSign() << " | Grade to execute: " << obj.getGradeToExecute();
	return (os);
}