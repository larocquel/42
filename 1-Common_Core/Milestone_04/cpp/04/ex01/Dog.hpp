/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:09:29 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 23:09:31 by leoaguia         ###   ########.fr       */
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
		virtual	~Dog();

		virtual	void	makeSound() const;
};

#endif