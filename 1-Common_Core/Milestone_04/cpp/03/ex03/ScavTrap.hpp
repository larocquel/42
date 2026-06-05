/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:22 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 17:10:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.hpp

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap	// DÚVIDA: Esse virtual permite que duas classes derivem da mesma base "Filhas da mesma Mãe"?
{
	public:
		// OCF
		ScavTrap();										// Default Constructor
		ScavTrap(const ScavTrap& other);				// Copy Constructor
		ScavTrap&	operator=(const ScavTrap& other);	// Copy Assignment Operator
		~ScavTrap();									// Destructor

		// Parametrized Constructor
		ScavTrap(std::string name);

		// Member Functions
		void	attack(const std::string& target);		// Override of ClapTrap's attack
		void	guardGate();							// Exclusive method
};

#endif