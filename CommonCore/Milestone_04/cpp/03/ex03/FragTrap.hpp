/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:50:16 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 17:10:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FragTrap.hpp

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		// Ortodox Canonical Form
		FragTrap();										// Default Constructor
		FragTrap(const FragTrap& other);				// Copy Constructor
		FragTrap&	operator=(const FragTrap& other);	// Copy Assignment Operator
		~FragTrap();									// Destructor

		// Parametrized Constructor
		FragTrap(std::string name);

		// Member Functions
		void	attack(const std::string& target);		// Override of ClapTrap's attack
		void	highFivesGuys(void);					// Exclusive method
};

#endif