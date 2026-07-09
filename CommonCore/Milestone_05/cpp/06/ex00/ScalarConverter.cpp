/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:11:30 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/09 03:18:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp

#include "ScalarConverter.hpp"
#include <cctype>

// Char Checker
bool	isChar(const std::string& literal)
{
	// Char: If the size is 1 and is printable and is not a number
	if ( (literal.length() == 1) && (literal[0] >= ' ' && literal[0] <= '~') && (isdigit(literal[0]) == false) )
	{
			return (true);
	}
	return (false);
}

// Int Checker
bool	isInt(const std::string& literal)
{
	// If the loop ends with only signal and numbers is an Int
	for (int i = 0; i < literal.length(); i++)
	{
		if ( (i == 0) && (literal[i] == '+') || (literal[i] == '-') )
			++i;
		if ( (i == literal.length() - 1) && (isdigit(literal[i])) )
		{
			return (true);
		}
		if ( !isdigit(literal[i]) )
			break;
	}
	return (false);
}

// Float Checker
bool	isFloat(const std::string& literal)
{
	// 1. Float must be at least a legth of 4 (0.0f)
	if (literal.length() < 4)
		return (false);

	// 2. Signal checker
	int	start = 0;

	if (literal[0] == '+' || literal[0] == '-')
		start = 1;

	if (literal.length() == start)
		return (false);

	int	dot = 0; // Flag to limit '.' qty by 1

	// 3. Loop until final of the string
	for (int i = start; i < literal.length(); i++)
	{
		// 4. After the signal we need a number (if there is no signal, we still need a number)
		if (!isdigit(start))
			break;

		// 5. We must have only one dot at the middle
		if ( literal[i] == '.')
		{
			if ( (dot == 1) || (i == 0) || (i = literal.length() - 1) )
				return (false);
			dot = 1;
			++i;
		}

		// 6. In the final, in order to be a float, we need:
		// Min length of 4
		// Only one '.' at the middle
		// Only one 'f' at the final
		if ( (i == literal.length() - 1) && (dot == 1) && (literal[i] == 'f') && (i != 0) )
		{
			return (true);
		}

		// 7. Regarding exceptions, we must have only digits in our string
		if ( !isdigit(literal[i]) )
			break;
	}
	return (false);
}

// Double Checker
bool	isDouble(const std::string& literal)
{
	// 1. Double must be at least a legth of 4 (0.0f)
	if (literal.length() < 4)
		return (false);

	// 2. Signal checker
	int	start = 0;

	if (literal[0] == '+' || literal[0] == '-')
		start = 1;

	if (literal.length() == start)
		return (false);

	int	dot = 0; // Flag to limit '.' qty by 1

	// 3. Loop until final of the string
	for (int i = start; i < literal.length(); i++)
	{
		// 4. After the signal we need a number (if there is no signal, we still need a number)
		if (!isdigit(start))
			break;

		// 5. We must have only one dot at the middle
		if ( literal[i] == '.')
		{
			if ( (dot == 1) || (i == 0) || (i = literal.length() - 1) )
				return (false);
			dot = 1;
			++i;
		}

		// 6. In the final, in order to be a double, we need:
		// Min length of 3
		// Only one '.' at the middle
		// End with a digit
		if ( (i == literal.length() - 1) && (dot == 1) && (isdigit(literal[i])) )
		{
			return (true);
		}

		// 7. Regarding exceptions, we must have only digits in our string
		if ( !isdigit(literal[i]) )
			break;
	}
	return (false);
}

static void	convert(const std::string& literal)
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

int	main()
{
	// char test
	std::string	c("A");

	std::cout << "isChar: " << (isChar(c) ? "Yes":"No") << std::endl;

	// int test
	std::string	i("1");

	std::cout << "isInt: " << (isInt(i) ? "Yes":"No") << std::endl;

	// int test
	std::string	f("+1.0f");

	std::cout << "isFloat: " << (isFloat(f) ? "Yes":"No") << std::endl;

	// double test
	std::string	d("+1.0");

	std::cout << "isDouble: " << (isDouble(d) ? "Yes":"No") << std::endl;

	return (0);
}