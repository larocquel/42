/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:05:43 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 14:11:03 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp

#include "Animal.hpp"

// Default Constructor:
Animal::Animal() : _type("Default")
{

}

// Copy Constructor:
Animal::Animal(const Animal& other)
{

}

// Copy Assignment Operator:
Animal&			Animal::operator=(const Animal& other)
{

}

// Destructor:
virtual			Animal::~Animal()
{

}

// Getter
std::string		Animal::getType(void)
{

}

// Methods
virtual	void	Animal::makeSound()
{

}