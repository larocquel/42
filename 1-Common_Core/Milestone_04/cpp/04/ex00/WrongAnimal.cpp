/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:52:04 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 14:31:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongAnimal.cpp

#include "WrongAnimal.hpp"

// Default Constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Constructor: WrongAnimal" << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy Constructor: WrongAnimal" << std::endl;
	*this = other;
}

// Copy Assignment Operator
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor: WrongAnimal" << std::endl;
}

// Method
void	WrongAnimal::makeSound() const
{
	std::cout << "THE JUNGLE IS NOT FRIENDLY" << std::endl;
}

// Getter
std::string	WrongAnimal::getType() const
{
	return(this->type);
}