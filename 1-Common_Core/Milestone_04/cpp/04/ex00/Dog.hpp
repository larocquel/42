/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:43:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 16:54:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.hpp

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
	// OCF
	Dog();
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog();

	// Method
	void	makeSound() const;
};

#endif