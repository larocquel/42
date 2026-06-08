/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:09:23 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 09:31:29 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.cpp

#include "Dog.hpp"

// Default Constructor
Dog::Dog()
{
	type = "Dog";
	this->_brain = new Brain();
	std::cout << "Constructor: Dog" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Copy Constructor: Dog" << std::endl;
}

// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->_brain = *other._brain;
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor: Dog" << std::endl;
}

// Method
void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
