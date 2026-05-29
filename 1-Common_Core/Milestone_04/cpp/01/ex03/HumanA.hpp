/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:21 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/29 19:03:21 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanA.hpp

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

// Class: Represents a human that MUST always have a weapon
class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;	// Private Attribute: Reference to a Weapon. It cannot be NULL and must be initialized upon creation.

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif