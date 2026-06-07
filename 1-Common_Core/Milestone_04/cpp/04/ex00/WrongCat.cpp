/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:54:34 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 14:32:41 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongCat.cpp

#include "WrongCat.hpp"

// Default Constructor
WrongCat::WrongCat()
{
	std::cout << "Constructor: WrongCat" << std::endl;
	type = "WrongCat";
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy Constructor: WrongCat" << std::endl;
	*this = other;
}

// Copy Assignment Operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "Destructor: WrongCat" << std::endl;
}

// Method
void	WrongCat::makeSound() const
{
	std::cout << "MEOWTH MEOWTH" << std::endl;
}
