/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:26:18 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:19 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.cpp

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default Constructor: Initializes the base AForm and sets a default target
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Default")
{
	std::cout << "Default Constructor: Shrubbery" << std::endl;
}

// Copy Constructor: Copies the base AForm and the specific target
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Shrubbery" << std::endl;
}

// Copy Assignment Operator: Assigns the base values and the target using polymorphism
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Destructor: Cleans up the Shrubbery object
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor: Shrubbery" << std::endl;
}

// Parametrized Constructor: Creates a Shrubbery form passing fixed grades to base class and a custom target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "Parametrized Constructor: Shrubbery" << std::endl;
}

// Execute Override: Validates requirements and generates an ASCII tree file if successful
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	// 1. Check AForm Requirements
	this->executeRequirements(executor);

	// 2. If no error, Create the file
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (file.is_open())
	{
		file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⠿⠿⢙⣟⡹⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣿⣿⡛⢿⡉⢑⡊⣙⠒⢡⢠⠤⢈⢉⣐⠇⠘⣻⣿⣿⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⡛⡥⡀⡄⣠⡍⠓⠁⡞⢂⠉⢸⡇⢃⠠⡅⢩⡕⠼⣛⣻⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⡿⢧⠴⠐⡓⠃⠻⣤⡇⢸⣧⢈⡇⠀⠀⣈⣈⣤⣤⡅⡢⢐⠨⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⠬⠉⡼⠦⠙⢟⢒⢠⣤⠀⠁⠿⠀⠠⠿⠯⠨⡼⠄⠠⠙⣠⡙⣈⣻⣿⣿\n";
		file << "⣿⣿⡿⠔⣡⠺⠟⢁⢀⣀⠉⢉⣀⠀⠀⠀⠀⣴⡀⣦⣤⡤⠆⢢⢈⡁⢐⠰⣽⣿\n";
		file << "⣿⣿⢗⡃⣫⡴⢰⣷⣥⣾⣸⣿⣿⣷⡄⠀⠀⢹⣿⣿⣿⣷⣼⣏⠢⡙⠰⣉⣿⣿\n";
		file << "⣿⣷⡇⡇⢣⣎⣧⣼⣿⣿⣿⣿⣿⣿⡟⠀⠀⠘⣿⣿⣿⣿⣿⣿⡇⣎⠂⡉⣿⣿\n";
		file << "⣿⣿⣿⢣⠸⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠹⢿⣿⣿⣿⣿⣿⠟⣀⢹⣿⣿\n";
		file << "⣿⣿⣿⣿⣇⢨⣉⡉⢉⡉⢀⢀⣤⠆⢠⡿⠀⢰⣤⡀⠉⠉⠙⠛⡁⣸⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣧⠲⡝⣆⢣⡻⠦⡣⡄⢆⣐⢇⢜⠥⢖⡥⢰⢣⠞⣱⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣿⣷⣬⣘⡊⢃⣓⡂⡑⡕⢪⢲⢐⣚⠂⢃⣋⣤⣾⣿⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣮⣐⣈⣨⣅⣁⣓⣵⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
		file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
		file.close();
	}
	else
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
	}
}