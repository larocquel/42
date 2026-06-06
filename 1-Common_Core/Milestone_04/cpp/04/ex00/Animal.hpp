/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:56:11 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 18:46:44 by leoaguia         ###   ########.fr       */
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
		virtual	~Animal();

		// Getter
		std::string	getType(void) const;

		// Method
		virtual	void	makeSound() const;
};

#endif