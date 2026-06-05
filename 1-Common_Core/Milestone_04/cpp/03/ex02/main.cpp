/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:50:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/05 13:22:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\n--- 1. INHERITANCE VISUALIZATION ---\n" << std::endl;
	ClapTrap robot1("Baymax");			// Base Parameterized Constructor
	std::cout << std::endl;
	FragTrap robot2("Bumblebee");		// Derived Parameterized Constructor
	std::cout << std::endl;
	FragTrap robot3("RoboCop");
	std::cout << std::endl;
	FragTrap robot4(robot2);			// Derived Copy Constructor
	std::cout << std::endl;
	FragTrap robot5;
	std::cout << std::endl;
	robot5 = robot3;					// Derived Copy Assignment Operator

	std::cout << "\n--- 2. OVERRIDE (ATTACK OUTPUTS) ---\n" << std::endl;
	robot1.attack("Bumblebee");			// Baymax ATTACKS Bumblebee, damage 0
	std::cout << std::endl;
	robot2.attack("Baymax");			// Bumblebee ATTACKS Baymax, damage 30

	std::cout << "\n--- 3. FRAGTRAP USING INHERITED FUNCTIONS ---\n" << std::endl;
	robot2.takeDamage(50);				// FragTrap takes damage using ClapTrap's function
	std::cout << std::endl;
	robot2.beRepaired(50);				// FragTrap repairs itself using ClapTrap's function

	std::cout << "\n--- 4. HIGH FIVE TEST ---\n" << std::endl;
	//robot1.highFivesGuys();			// UNCOMMENT TO PROVE COMPILATION ERROR (Base class doesn't have this)
	robot2.highFivesGuys();				// Derived class exclusive function

	std::cout << "\n--- 5. DESTRUCTORS ---\n" << std::endl;
	// Fun to see the LIFO (Last In, First Out) in action
	return (0);
}