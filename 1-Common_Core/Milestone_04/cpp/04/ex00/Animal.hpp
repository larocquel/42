/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:56:11 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:47:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.hpp

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		// Ortodox Canonical Form
		Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual	~Animal();		// Virtual is critical for proper cleanup

		// Getter
		std::string	getType(void) const;

		// Polymorphic Method
		virtual	void	makeSound() const;
};

#endif