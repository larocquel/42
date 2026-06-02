/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 17:10:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp

#include "Fixed.hpp"

// Constructor:
Fixed::Fixed() : _value(0) {}

// Copy Constructor:
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// Copy Assignment Operator:
Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor:
Fixed::~Fixed() {}

// Getter:
int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

// Setter:
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Int Constructor:
Fixed::Fixed(int n)
{
	this->_value = n << _fBits;
}

// Float Constructor
Fixed::Fixed(float n)
{
	float tmp = n * (1 << _fBits);
	this->_value = roundf(tmp);
}

// Converter: Converts to Integer
int		Fixed::toInt(void) const
{
	return (this->_value >> _fBits);
}

// Converter: Converts to Float
float	Fixed::toFloat(void) const
{
	float	tmp = (float)this->_value / (1 << _fBits);
	return (tmp);
}

// 1. Comparison Operators

// Greater Operator:
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

// Less Operator:
bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

// Greater Or Equal Operator:
bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

// Less Or Equal Operator:
bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

// Equal Operator:
bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

// Different Operator:
bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

// 2. Arithmetic Operators

// Add Operator:
Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

// Subtraction Operator:
Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

// Multiplication Operator:
Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

// Division Operator:
Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

// 3. Increment Operators

// Pré-incremento (Retorna o próprio objeto já alterado por referência)
Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

// Pós-incremento (Retorna uma cópia do objeto ANTES de ser alterado. O 'int' fantasma serve só pro C++ diferenciar)
Fixed Fixed::operator++(int)
{
	Fixed	copy(*this);
	this->_value++;
	return (copy);
}

// Pré-decremento (Retorna o próprio objeto já alterado por referência)
Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

// Pós-decremento (Retorna uma cópia do objeto ANTES de ser alterado. O 'int' fantasma serve só pro C++ diferenciar)
Fixed Fixed::operator--(int)
{
	Fixed	copy(*this);
	this->_value--;
	return (copy);
}

// Min e Max (Funções Estáticas)

// Min
Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

// Min constant
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

// Max
Fixed&			Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

// Max constant
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

// Insertion Operator: Overloads the << operator to print the float representation
std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
