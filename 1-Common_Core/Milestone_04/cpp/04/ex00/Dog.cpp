/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:05:09 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 13:39:09 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.cpp

#include "Dog.hpp"

// Default Constructor
Dog::Dog()
{
	std::cout << "Constructor: Dog" << std::endl;
	type = "Dog";
}

// Copy Constructor
Dog::Dog(const Dog& other)
{
	std::cout << "Copy Constructor: Dog" << std::endl;
	*this = other;
}

// Copy Assignment Operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "Destructor: Dog" << std::endl;
}

// Method
void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}
