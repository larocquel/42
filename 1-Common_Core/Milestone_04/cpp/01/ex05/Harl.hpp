/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:31:20 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/27 21:25:03 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.hpp

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

// DUVIDA: Qual motivo de ter colocado os métodos no private?
class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
