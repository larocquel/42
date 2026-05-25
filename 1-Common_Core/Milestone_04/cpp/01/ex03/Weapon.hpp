/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:19:58 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/25 17:57:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Weapon.hpp

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		const std::string &getType(void);	// Returns a constant reference to _type
};

#endif