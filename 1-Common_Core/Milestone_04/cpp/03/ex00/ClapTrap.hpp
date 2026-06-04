/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:43:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/04 14:12:11 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iosteram>
# include <string>

class ClapTrap
{
	private:
			std::string	_name;
			int			_hitPoints;
			int			_energyPoints;
			int			_attackDamage;
	public:

	// Ortodox Canonical Form
	ClapTrap(std::string Name);						// Constructor
	ClapTrap(const ClapTrap& other);				// Copy Contructor
	ClapTrap&	operator=(const ClapTrap& other);	// Copy Assignment Operator
	~ClapTrap();

	// Mandatory Methods
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif