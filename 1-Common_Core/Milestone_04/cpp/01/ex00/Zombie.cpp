/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:55:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/22 20:01:24 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.cpp

#include "Zombie.hpp"

// Constructor: Inicialização ao compilar
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << std::left << std::setw(10) << _name << ": Borned"  << std::endl;
}

// Método público: Anunciar um zombie
void	Zombie::announce(void)
{
	std::cout << std::left << std::setw(10) << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor:
// Dúvida: O destructor é chamado sempre automaticamente ou somente quando faço delete?
Zombie::~Zombie()
{
	std::cout << std::left << std::setw(10) << _name << ": Destructed" << std::endl;
}