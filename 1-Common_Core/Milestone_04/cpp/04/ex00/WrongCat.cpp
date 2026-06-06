/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:35:18 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:24:39 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongCat.cpp

#include "WrongCat.hpp"

// Constructor:
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Constructor: WrongCat was born!" << std::endl;
}

// Copy Constructor:
WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy Constructor: WrongCat was born!" << std::endl;
	*this = other;
}

// Copy Assignment Operator:
WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor:
WrongCat::~WrongCat()
{
	std::cout << "Destructor: WrongCat died!" << std::endl;

}

// Method:
void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: MIAU!" << std::endl;
}