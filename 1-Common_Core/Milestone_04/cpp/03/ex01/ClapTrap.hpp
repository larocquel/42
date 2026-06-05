/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:40:58 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 10:53:30 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.hpp

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:	// Tive que trocar de private para protected a fim de que as classes filhas tenham acessos a esses atributos
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