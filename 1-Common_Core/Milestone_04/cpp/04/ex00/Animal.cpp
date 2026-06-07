/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 10:57:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 13:39:25 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp

#include "Animal.hpp"

// Default Constructor
Animal::Animal() : type("Animal")
{
	std::cout << "Constructor: Animal" << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal& other)
{
	std::cout << "Copy Constructor: Animal" << std::endl;
	*this = other;
}

// Copy Assignment Operator
Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal()
{
	std::cout << "Destructor: Animal" << std::endl;
}

// Method
void	Animal::makeSound() const
{
	std::cout << "WELCOME TO THE JUNGLE" << std::endl;
}

// Getter
std::string	Animal::getType() const
{
	return(type);
}