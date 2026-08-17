/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:11:13 by leoaguia          #+#    #+#             */
/*   Updated: 2026/08/17 20:09:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp

#include "ScalarConverter.hpp"

enum Type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID};

// Orthodox Canonical Form
// All members are private: the class must never be instantiated.
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter&) {return (*this);}
ScalarConverter::~ScalarConverter() {}

// Detects what type the literal string represents
static int  detectType(const std::string& literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff"
        || literal == "nan" || literal == "+inf" || literal == "-inf")
        return (PSEUDO);

    if (literal.length() == 1
        && std::isprint(static_cast<unsigned char>(literal[0]))
        && !std::isdigit(static_cast<unsigned char>(literal[0])))
        return (CHAR);

    int dot = 0;
    int f = 0;
    int digits = 0;

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

    if (digits == 0)
        return (INVALID);
    if (dot == 0 && f == 0)
        return (INT);
    if (dot == 1 && f == 1 && literal[literal.length() - 1] == 'f')
        return (FLOAT);
    if (dot == 1 && f == 0)
        return (DOUBLE);

    return (INVALID);
}

// Original string is a CHAR
static void print(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// Original string is an INT
static void print(int i)
{
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

// Original string is a FLOAT
static void print(float f)
{
    std::cout << "char: ";
    if (f < 0 || f > 127 || f != f) // (f != f) verifies if is nan
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || f != f)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    // If float - rounded float = 0 the number is rounded
    std::cout << "float: " << f << (f - std::floor(f) == 0.0f ? ".0f" : "f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << (f - std::floor(f) == 0.0f ? ".0" : "") << std::endl;
}

// Original string is a DOUBLE
static void print(double d)
{
    std::cout << "char: ";
    if (d < 0 || d > 127 || d != d)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX) || d != d)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << (d - std::floor(d) == 0.0 ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d - std::floor(d) == 0.0 ? ".0" : "") << std::endl;
}

// Deal with pseudo directly
static void printPseudo(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// Detects the literal's type, parses it, and prints
void ScalarConverter::convert(const std::string& literal)
{
    int type = detectType(literal);

    switch (type)
    {
        case CHAR:
            print(literal[0]);
            break;
        case INT:
        {
            long l = std::strtol(literal.c_str(), NULL, 10);
            if (l > INT_MAX || l < INT_MIN)
                std::cout << "invalid input: int overflow" << std::endl;
            else
                print(static_cast<int>(l));
            break;
        }
        case FLOAT:
            print(static_cast<float>(std::strtod(literal.c_str(), NULL)));
            break;
        case DOUBLE:
            print(std::strtod(literal.c_str(), NULL));
            break;
        case PSEUDO:
            printPseudo(literal);
            break;
        default:
            std::cout << "invalid input" << std::endl;
            break;
    }
}