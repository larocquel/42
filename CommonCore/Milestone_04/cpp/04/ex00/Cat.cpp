/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:16:10 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 14:39:24 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.cpp

#include "Cat.hpp"

// Default Constructor
Cat::Cat()
{
	std::cout << "Constructor: Cat" << std::endl;
	type = "Cat";
}

// Copy Constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy Constructor: Cat" << std::endl;
	*this = other;
}

// Copy Assignment Operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destructor: Cat" << std::endl;
}

// Method
void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
