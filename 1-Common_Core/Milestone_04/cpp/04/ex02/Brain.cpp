/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:52:51 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 10:52:52 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Brain.cpp

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor: Brain" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy Constructor: Brain" << std::endl;
	*this = other;
}

Brain&			Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor: Brain" << std::endl;
}

void			Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		this->_ideas[index] = idea;
	}
}

const std::string&	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (this->_ideas[index]);
	}
	return (this->_ideas[0]);
}