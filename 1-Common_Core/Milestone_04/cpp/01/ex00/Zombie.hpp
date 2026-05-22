/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:54:36 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 20:01:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.hpp

#include <iostream>
#include <iomanip>

class Zombie
{
	private:
		std::string	_name;
		
	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};