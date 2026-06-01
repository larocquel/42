/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:12:38 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 14:30:29 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Construtor Padrão
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Construtor de cópia
Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this._value = other._value;
}

// Operador de cópia
Fixed&	operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this._value = other._value;
	return (&this);
}

// Destrutor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Getter: Returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value); // DÚVIDA: Não entendi o que esse "this->" significa
}

// Setter: Sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw)
{
	this._value = raw;
}