/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:43:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/04 23:25:10 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.hpp

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

	public:
		// OCF: Ortodox Canonical Form
		ClapTrap();										// Constructor
		ClapTrap(const ClapTrap& other);				// Copy Constructor
		ClapTrap&	operator=(const ClapTrap& other);	// Copy Assignment Operator
		~ClapTrap();									// Destructor

		// Parametrized Constructor
		ClapTrap(std::string name);

		// Member Functions (Actions)
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif