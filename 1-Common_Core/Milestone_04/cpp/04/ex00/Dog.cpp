/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:05:49 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 17:17:53 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.cpp

#include "Dog.hpp"

// Constructor:
Dog::Dog()
{
	_type = "Dog";
	std::cout << "Constructor: A Dog was born!" << std::endl;
}

// Copy Constructor:
Dog::Dog(const Dog& other)
{
	std::cout << "Copy Constructor: A Dog was born!" << std::endl;
	*this = other;
}

// Copy Assignment Operator:
Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor:
Dog::~Dog()
{
	std::cout << "Destructor: Dog died!" << std::endl;

}

// Method:
void	Dog::makeSound() const
{
	std::cout << "Dog: AUAU!" << std::endl;
}