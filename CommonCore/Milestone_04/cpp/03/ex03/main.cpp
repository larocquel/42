/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:50:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 18:30:21 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n--- 1. INHERITANCE & DIAMOND CONSTRUCTION ---\n" << std::endl;
	ClapTrap robot1("R2-D2");				// Base
	std::cout << std::endl;
	DiamondTrap robot2("Megazord");			// The Ultimate Hybrid
	std::cout << std::endl;
	DiamondTrap robot3("Megatron");
	std::cout << std::endl;
	DiamondTrap robot4(robot2);				// Copy Constructor
	std::cout << std::endl;
	robot3 = robot4;						// Copy Assignment Operator

	std::cout << "\n--- 2. ATTACK TEST (MUST BE SCAVTRAP'S ATTACK) ---\n" << std::endl;
	robot1.attack("Megazord");				// R2-D2 tries his best... (0 damage)
	std::cout << std::endl;
	robot2.attack("R2-D2");					// Megazord violently attacks! (ScavTrap override)

	std::cout << "\n--- 3. BASE CLAPTRAP FUNCTIONS ---\n" << std::endl;
	robot2.takeDamage(20);					// Takes 20 damage, 80 HP left
	std::cout << std::endl;
	robot2.beRepaired(10);					// Heals 10 HP, 90 HP left

	std::cout << "\n--- 4. MULTIPLE INHERITANCE POWERS ---\n" << std::endl;
	robot2.guardGate();						// Using ScavTrap's exclusive ability
	std::cout << std::endl;
	robot2.highFivesGuys();					// Using FragTrap's exclusive ability

	std::cout << "\n--- 5. DIAMONDTRAP EXCLUSIVE (WHO AM I) ---\n" << std::endl;
	robot2.whoAmI();						// Megazord thinks about R2-D2_clap_name

	std::cout << "\n--- 6. DESTRUCTORS (THE GRAND FINALE) ---\n" << std::endl;
	// Get ready to see the massive reverse destruction chain
	return (0);
}