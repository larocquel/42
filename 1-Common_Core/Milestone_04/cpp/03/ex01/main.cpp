/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:40:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 12:21:11 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n--- 1. INHERITANCE VISUALIZATION ---\n" << std::endl;
	ClapTrap robot1("WALL-E");			// Base Parameterized Constructor
	std::cout << std::endl;
	ScavTrap robot2("EVA");				// Derived Parameterized Constructor
	std::cout << std::endl;
	ScavTrap robot3("Marvin");
	std::cout << std::endl;
	ScavTrap robot4;
	std::cout << std::endl;
	robot4 = robot3;					// Derived Copy Assignment Operator

	std::cout << "\n--- 2. OVERRIDE (ATTACK OUTPUTS) ---\n" << std::endl;
	robot1.attack("EVA");				// WALL-E ATTACKS EVA, damage 0
	std::cout << std::endl;
	robot2.attack("WALL-E");			// EVA ATTACKS WALL-E, damage 20

	std::cout << "\n--- 3. SCAVTRAP USING INHERITED FUNCTIONS ---\n" << std::endl;
	robot2.takeDamage(50);				// ScavTrap takes damage using ClapTrap's function
	std::cout << std::endl;
	robot2.beRepaired(50);				// ScavTrap repairs itself using ClapTrap's function

	std::cout << "\n--- 4. GUARDGATE TEST ---\n" << std::endl;
	//robot1.guardGate();				// UNCOMMENT TO PROVE COMPILATION ERROR
	robot2.guardGate();					// Derived class exclusive function

	std::cout << "\n--- 5. DESTRUCTORS ---\n" << std::endl;
	// Fun to see the LIFO in action
	return (0);
}