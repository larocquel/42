/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:11:13 by leoaguia          #+#    #+#             */
/*   Updated: 2026/08/06 03:26:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp

#include "ScalarConverter.hpp"

enum Type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID};

// Orthodox Canonical Form
// All members are private: the class must never be instantiated.
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {return (*this);}
ScalarConverter::~ScalarConverter() {}

// Auxiliar Functions

// Detects what type the literal string represents
static int	detectType(const std::string& literal)
{
	// 1. Pseudo-Literals
	if (literal == "nanf" || literal == "+inff" || literal == "-inff"
		|| literal == "nan" || literal == "+inf" || literal == "-inf")
		return (PSEUDO);

	// 2. Char
	// A char must be one character, printable and non-digit
	if (literal.length() == 1
		&& std::isprint(static_cast<unsigned char>(literal[0]))
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
		return (CHAR);

	// 3. Numbers (Int, Float or Double) - Counting principle
	int	dot = 0;
	int	f = 0;
	int	digits = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		else if (literal[i] == '.')
			dot++;
		else if (literal[i] == 'f')
			f++;
		else if (std::isdigit(static_cast<unsigned char>(literal[i])))
			digits++;
		else
			return (INVALID);
	}

	// Invalid: A number type must have at least one digit
	if (digits == 0)
		return (INVALID);

	// Int: Only digits (can have one signal)
	if (dot == 0 && f == 0)
		return (INT);

	// Float: One '.', One 'f', and 'f' must be the last character
	if (dot == 1 && f == 1 && literal[literal.length() - 1] == 'f')
		return (FLOAT);

	// Double: One '.' only
	if (dot == 1 && f == 0)
		return (DOUBLE);

	// Invalid: Any other combination
	return (INVALID);
}

// Prints the value as a char or a message
static void	printChar(double value)
{
	// 1. Description
	std::cout << "char: ";

	// 2. Impossible, not printable, possible
	if (value > CHAR_MAX || value < CHAR_MIN || value != value)
		std::cout << "impossible";
	else
	{
		char	c = static_cast<char>(value);

		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";
	}

	// 3. End Line
	std::cout << std::endl;
}

// Prints the value as an int or a message
static void	printInt(double value)
{
	// 1. Description
	std::cout << "int: ";

	// 2. Is possible?
	// value != value catches NaN
	if (value > INT_MAX || value < INT_MIN || value != value)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);

	// 3. End line
	std::cout << std::endl;
}

// Prints the value as a float
static void	printFloat(double value)
{
	// 1. Cast
	float	f = static_cast<float>(value);

	// 2. Description
	std::cout << "float: ";

	// 3. Round numbers get one forced decimal place, pseudos are printed as they are
	if (f != std::numeric_limits<float>::infinity()
		&& f != -std::numeric_limits<float>::infinity()
		&& std::floor(f) == f)
	{
		std::cout << std::fixed << std::setprecision(1) << f;
	}
	else
	{
		std::cout << f;
	}

	// 4. Adds 'f' and Ends the line
	std::cout << "f" << std::endl;
}

// Prints the value as a double
static void	printDouble(double value)
{
	// 1. Description
	std::cout << "double: ";

	// 2. Round numbers get one forced decimal place, pseudos are printed as they are
	if (value != std::numeric_limits<double>::infinity()
		&& value != -std::numeric_limits<double>::infinity()
		&& std::floor(value) == value)
	{
		std::cout << std::fixed << std::setprecision(1) << value;
	}
	else
	{
		std::cout << value;
	}

	// 3. Ends the line
	std::cout << std::endl;
}

// Detects the literal's type, parses it, and prints
void ScalarConverter::convert(const std::string& literal)
{
	// 1. Find out the type
	int	type = detectType(literal);

	// 2. Double hub
	double	value;

	if (type == INVALID)
	{
		std::cout << "invalid input" << std::endl;
		return ;
	}
	else if (type == CHAR)
	{
		value = static_cast<double>(literal[0]);
	}
	else if (type == PSEUDO)
	{
		if (literal[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else if (literal[0] == '+')
			value = std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::quiet_NaN();
	}
	else
	{
		value = strtod(literal.c_str(), NULL);
	}

	// 3. Print all types
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

