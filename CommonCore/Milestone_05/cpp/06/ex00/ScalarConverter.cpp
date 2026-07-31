/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:11:13 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/31 06:22:08 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>	// std::isdigit, std::isprint
#include <cstdlib>	// Conversion
#include <climits>	// INT_MIN, INT_MAX
#include <cmath>	// Helps with nan/inf, if needed

enum Type {CHAR, INT, FLOAT, DOUBLE, INVALID};

// Ortodoxal Canonical Form
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {return (*this);}
ScalarConverter::~ScalarConverter() {}

// Auxiliar Functions

// Detects what type the literal string represents
static int	detectType(const std::string& literal)
{
	// char
	if (literal.length() == 1 && isprint(literal[0] && !isdigit(literal[0]))
		return (CHAR);
	// int, float, double or invalid
	int neg = 0;
	int dot = 0;
	int f = 0;
	int	digits = 0;
	for (int i = 0; i < literal.length(); i++)
	{
		// signal
		if (i == 0 && literal[0] == '-')
			neg++;
		// point
		else if (literal[i] == '.')
			dot++;
		// f
		else if (literal[i] == 'f')
			f++;
		// digits
		else if (std::isdigit(literal[i]))
			digits++;
	}
	// int
	if ((neg == 0 && digits = literal.length()) || (neg == 1 && digits = literal.length - neg))
		return (INT);
	// float
	if (((neg == 0 && dot == 1 && f == 1 && digits == literal.length() - dot - f) || (neg == 1 && dot == 1 && f == 1 && digits == literal.length() - neg - dot - f)) && literal[literal.length - 1] == 'f')
		return (FLOAT);
	// double
	if ((neg == 0 && dot == 1 && f == 0 && digits == literal.length() - dot) || (neg == 1 && dot == 1 && f == 0 && digits == literal.length() - neg - dot))
		return (DOUBLE);
	// invalid
	return (invalid);
}

//
static void	printChar(double value)
{

}

static void	printInt(double value)
{

}

static void	printFloat(double value)
{

}

static void	printDouble(double value)
{

}

// Convert Method
void ScalarConverter::convert(const std::string& literal)
{

}


