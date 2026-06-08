/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:09:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 00:57:27 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main()
{
	std::cout << "------1. INSTANTIATE------" << std::endl;

	Animal*	animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "-----2. TYPES & SOUNDS----" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << " - " << animals[i]->getType() << " sound: " ;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "--------4. DELETE---------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "----5. DEEP COPY TEST----" << std::endl;
	Animal*	original = new Dog();
	std::cout << std::endl;
	Animal* copy;

	copy = original;

	// original
	std::cout << "original - " << original->getType() << " sound: " ;
	original->makeSound();

	// copy
	std::cout << "copy     - " << copy->getType() << " sound: " ;
	copy->makeSound();

	delete copy;

	// is original alive?
	std::cout << "original - " << original->getType() << " sound: " ;
	original->makeSound();

	// is copy alive?
	std::cout << "copy     - " << copy->getType() << " sound: " ;
	copy->makeSound();

	delete original;

	return (0);
}