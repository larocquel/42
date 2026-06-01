/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:38:33 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 21:24:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp

#include "Fixed.hpp"

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fBits;	// Deslocamos o inteiro fBits(8) casas para a esquerda e guardamos essa transformação em _value
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float	tmp = n * (1 << _fBits);
	this->_value = roundf(tmp);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _fBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fBits));
}
