/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:20:43 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/25 17:59:47 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanB.hpp

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

// Class: Represents a human that may or may not have a weapon
class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;	// Private Attribute: Pointer to a Weapon. It can be NULL if the human is unarmed.

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif