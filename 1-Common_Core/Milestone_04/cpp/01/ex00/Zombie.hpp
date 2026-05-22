/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:54:36 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 21:35:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.hpp

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif