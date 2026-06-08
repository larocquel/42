/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:09:04 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 11:07:59 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.cpp

#include "Cat.hpp"

// Default Constructor
Cat::Cat()
{
	std::cout << "Constructor: Cat" << std::endl;
	type = "Cat";
	this->_brain = new Brain();
}

// Copy Constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy Constructor: Cat" << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->_brain = *other._brain;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor: Cat" << std::endl;
}

// Method
void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
