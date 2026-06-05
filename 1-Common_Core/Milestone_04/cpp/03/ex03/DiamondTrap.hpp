/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:06:28 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 17:50:53 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamondTrap.hpp

#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap(std::string name);

		void	attack(const std::string& target);

		void 	whoAmI();
};

#endif