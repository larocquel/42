/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:06:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:53:12 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.cpp

#include "Cat.hpp"

// Constructor
Cat::Cat()
{
	_type = "Cat";
	std::cout << "Constructor: Cat was born!" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat& other)
{
	std::cout << "Copy Constructor: Cat was born!" << std::endl;
	*this = other;
}

// Copy Assignment Operator
Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destructor: Cat died!" << std::endl;

}

// Method
void	Cat::makeSound() const
{
	std::cout << "Cat: MIAU!" << std::endl;
}