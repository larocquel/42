/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:24:51 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:51:42 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongAnimal.hpp

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		~WrongAnimal(); // Non-virtual on purpose to demonstrate fails

		// Getter
		std::string	getType(void) const;

		// Non-virtual Method to demonstrate Static Binding
		void	makeSound() const;
};

#endif