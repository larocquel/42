/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:41:22 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 10:56:58 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.hpp

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap // DÚVIDA: Até os atributos prvados do ClapTrap torna-se publicos para o ScavTrap?
{
	private:

	public:
		// OCF: Qual a necessidade de redeclarar a OCF?
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();

		// Parametrized Constructor
		ScavTrap(std::string name);

		// Override
		void	attack(const std::string& target);

		// Exclusive method
		void	guardGate();
};

#endif