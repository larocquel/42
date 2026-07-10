/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:11:30 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/10 01:06:06 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp

#include "ScalarConverter.hpp"

// Char Checker: Length = 1, Printable, and Not a digit
bool	isChar(const std::string& literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		return (true);
	}
	return (false);
}

// Int Checker
bool	isInt(const std::string& literal)
{
	// Um sinal + ou -
	// Somente digitos no restante
	// int = 4 bytes: limte superior no int 2^31 - 1 e limite inferior -2^31
}

// Float Checker
bool	isFloat(const std::string& literal)
{

}

// Double Checker
bool	isDouble(const std::string& literal)
{

}

void	ScalarConverter::convert(const std::string& literal)
{
	char type = 'n'; // I'll use n for none, c for char, i for int, f for float, d for double and pl dor pseudo-literal

	// 1 - Parse and Detect: literal is char, int, float, double or pseudo-literal(nan, +inf, -inff, etc)

	if (isChar(literal))
		type = 'c';
	else if (isInt(literal))
		type = 'i';
	else if (isFloat(literal))
		type = 'f';
	else if (isDouble(literal))
		type = 'd';

	// 2 - Print: char value, int value, float value, double value
}