/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 18:15:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp

#include "Fixed.hpp"

// Default Constructor: Initializes the value to 0
Fixed::Fixed() : _value(0) {}

// Copy Constructor: Creates a new object as a copy of another
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// Copy Assignment Operator: Assigns values from one object to another
Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor: Cleans up the object
Fixed::~Fixed() {}

// Getter: Returns the raw internal integer value
int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

// Setter: Sets the raw internal integer value
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Int Constructor: Converts an integer to fixed-point format
Fixed::Fixed(const int n)
{
	this->_value = n << _fBits;
}

// Float Constructor: Converts a float to fixed-point format
Fixed::Fixed(const float n)
{
	float tmp = n * (1 << _fBits);
	this->_value = roundf(tmp);
}

// Int Converter: Converts the fixed-point value back to an integer
int		Fixed::toInt(void) const
{
	return (this->_value >> _fBits);
}

// Float Converter: Converts the fixed-point value back to a float
float	Fixed::toFloat(void) const
{
	float	tmp = (float)this->_value / (1 << _fBits);
	return (tmp);
}

// COMPARISON OPERATORS

// Greater Operator:
bool	Fixed::operator>(const Fixed& other) const
{ return (this->_value > other._value); }

// Less Operator:
bool	Fixed::operator<(const Fixed& other) const
{ return (this->_value < other._value); }

// Greater Or Equal Operator:
bool	Fixed::operator>=(const Fixed& other) const
{ return (this->_value >= other._value); }

// Less Or Equal Operator:
bool	Fixed::operator<=(const Fixed& other) const
{ return (this->_value <= other._value); }

// Equal Operator:
bool	Fixed::operator==(const Fixed& other) const
{ return (this->_value == other._value); }

// Different Operator:
bool	Fixed::operator!=(const Fixed& other) const
{ return (this->_value != other._value); }

// ARITHMETIC OPERATORS

// Add Operator:
Fixed	Fixed::operator+(const Fixed& other) const
{ return (Fixed(this->toFloat() + other.toFloat())); }

// Subtraction Operator:
Fixed	Fixed::operator-(const Fixed& other) const
{ return (Fixed(this->toFloat() - other.toFloat())); }

// Multiplication Operator:
Fixed	Fixed::operator*(const Fixed& other) const
{ return (Fixed(this->toFloat() * other.toFloat())); }

// Division Operator:
Fixed	Fixed::operator/(const Fixed& other) const
{ return (Fixed(this->toFloat() / other.toFloat())); }

// INCREMENT OPERATORS

// Pre-increment Operator (++a)
Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

// Post-increment Operator (a++)
Fixed Fixed::operator++(int)
{
	Fixed	copy(*this);
	this->_value++;
	return (copy);
}

// Pre-decrement Operator (--a)
Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

// Post-decrement Operator (a--)
Fixed Fixed::operator--(int)
{
	Fixed	copy(*this);
	this->_value--;
	return (copy);
}

// Min & Max (Static Functions)

// Min
Fixed&			Fixed::min(Fixed& a, Fixed& b)
{ return ((a < b) ? a : b); }

// Min Constant
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{ return ((a < b) ? a : b); }

// Max
Fixed&			Fixed::max(Fixed& a, Fixed& b)
{ return ((a > b) ? a : b); }

// Max Constant
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{ return ((a > b) ? a : b); }

// Insertion Operator: Overloads the << operator to print the float representation
std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
