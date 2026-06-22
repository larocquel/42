/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:38:33 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 09:03:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp

#include "Fixed.hpp"

// Default Constructor: Initializes the fixed-point value to 0
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor: Creates a new object as a copy of 'other'
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy Assignment Operator: Assigns the value of 'other' to the current object
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor: Prints a destruction message
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Getter: Returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
	return (this->_value);
}

// Setter: Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Int Constructor: Converts an integer to a fixed-point value
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fBits;
}

// Float Constructor: Converts a float to a fixed-point value
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;

	float   tmp = n * (1 << _fBits);

	this->_value = roundf(tmp);
}

// toInt: Converts the fixed-point value to an integer
int Fixed::toInt(void) const
{
	return (this->_value >> _fBits);
}

// toFloat: Converts the fixed-point value to a floating-point number
float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fBits));
}

// Insertion Operator: Overloads the << operator to print the float representation
std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}