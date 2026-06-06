/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:05:43 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 17:10:17 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp

#include "Animal.hpp"

// Default Constructor:
Animal::Animal() : _type("Default")
{
	std::cout << "Constructor: An Animal was born!" << std::endl;
}

// Copy Constructor:
Animal::Animal(const Animal& other)
{
	std::cout << "Copy Constructor: An Animal was born!" << std::endl;
	*this = other;
}

// Copy Assignment Operator:
Animal&			Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor:
Animal::~Animal()
{
	std::cout << "Destructor: Animal died!" << std::endl;
}

// Getter
std::string		Animal::getType(void) const
{
	return(this->_type);
}

// Methods
void	Animal::makeSound() const
{
	std::cout << "Animal: WELCOME TO THE JUNGLE!" << std::endl;
}