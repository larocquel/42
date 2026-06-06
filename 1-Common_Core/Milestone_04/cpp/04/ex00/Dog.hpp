/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:43:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:48:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.hpp

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		// Overridden Method
		void	makeSound() const;
};

#endif