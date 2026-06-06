/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:02:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 14:05:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.hpp

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class CAT : public Animal
{
	public:
	// OCF
	Cat();
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	virtual ~Cat();

	// Method
	void	makeSound();
};

#endif