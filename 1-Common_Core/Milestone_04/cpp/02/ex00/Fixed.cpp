/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:12:38 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 17:59:45 by leoaguia         ###   ########.fr       */
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

// Setter: Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}