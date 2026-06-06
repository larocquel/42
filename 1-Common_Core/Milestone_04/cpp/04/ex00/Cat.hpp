/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:02:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:49:30 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.hpp

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		// Overridden Method
		void	makeSound() const;
};

#endif