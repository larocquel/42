/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/29 13:46:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.cpp

#include "ShrubberyCreationForm.hpp"
#include <fstream>


// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Default")
{
	std::cout << "Default Constructor: Shrubbery" << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy Constructor: Shrubbery" << std::endl;
}

// Copy Assignment Operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // DÚVIDA: Não entendi a sintexe (other)
		this->_target = other._target;
	}
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor: Shrubbery" << std::endl;
}

// Parametrized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "Parametrized Constructor: Shrubbery" << std::endl;
}

// Virtual Pure Method from Base Class
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