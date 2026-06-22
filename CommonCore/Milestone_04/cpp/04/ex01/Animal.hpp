/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 23:08:55 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 23:08:56 by leoaguia         ###   ########.fr       */
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
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual	~Animal();

		virtual	void	makeSound() const;
		std::string		getType() const;
};

#endif