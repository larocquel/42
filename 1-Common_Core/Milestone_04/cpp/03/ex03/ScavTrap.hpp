/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:22 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 18:45:59 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.hpp

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap	// "virtual" allow a lot of derived classes from a base one, "infinite kids from the same mother"
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