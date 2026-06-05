/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:40:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 09:40:54 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n--- 1. CONSTRUCTORS & ORTHODOX CANONICAL FORM TESTS ---" << std::endl;
	ClapTrap robot1("WALL-E");			// Parameterized Constructor
	ClapTrap robot2("C3PO");			// Parameterized Constructor
	ClapTrap robot3(robot1);			// Copy Constructor
	ClapTrap robot4;					// Default Constructor

	robot4 = robot2;					// Copy Assignment Operator

	std::cout << "\n--- 2. BASIC ACTIONS (ATTACK & REPAIR) ---" << std::endl;
	robot1.attack("C3PO");				// WALL-E ATTACKS C3PO, pdf sets damage to 0
	robot2.takeDamage(0);				// WALL-E deals 0 damage originally
	robot2.beRepaired(5);				// C3PO heals 5 HP (Costs 1 Energy)

	std::cout << "\n--- 3. DEATH TEST (NO HIT POINTS) ---" << std::endl;
	robot1.takeDamage(20);				// WALL-E takes 20 damage (HP drops to 0)
	robot1.attack("C3PO");				// Should fail (HP is 0)
	robot1.beRepaired(5);				// Should fail (HP is 0)

	std::cout << "\n--- 4. EXHAUSTION TEST (NO ENERGY POINTS) ---" << std::endl;
	// robot2 started with 10 Energy. Used 1 for beRepaired. 9 left.
	for (int i = 0; i < 10; i++)
	{
		robot2.attack("a rock");		// Will work 9 times, fail on the 10th
	}

	std::cout << "\n--- 5. DESTRUCTORS ---" << std::endl;
	return (0);
}