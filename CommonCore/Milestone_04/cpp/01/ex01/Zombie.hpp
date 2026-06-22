/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 01:07:31 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/24 02:58:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.hpp

#ifndef	ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class	Zombie
{
	private:
		std::string	_name;
		int			_index;

	public:
		Zombie();
		void	setNameAndIndex(std::string name, int index);
		void	announce(int index);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif