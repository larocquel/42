/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:35:00 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:24:33 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongAnimal.cpp

#include "WrongAnimal.hpp"

// Default Constructor:
WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "Constructor: WrongAnimal was born!" << std::endl;
}

// Copy Constructor:
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy Constructor: WrongAnimal was born!" << std::endl;
	*this = other;
}

// Copy Assignment Operator:
WrongAnimal&			WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor:
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor: WrongAnimal died!" << std::endl;
}

// Getter
std::string		WrongAnimal::getType(void) const
{
	return(this->_type);
}

// Methods
void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: WELCOME TO THE JUNGLE!" << std::endl;
}