/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:53:13 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/08 11:04:43 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int	main()
{
	// std::cout << "------1. INSTANTIATE------" << std::endl;
	Animal	*d = new Dog();
	std::cout << std::endl;

	// 	std::cout << "-----2. TYPES & SOUNDS----" << std::endl;
	std::cout << d->getType() << " sound: ";
	d->makeSound();
	std::cout << std::endl;

	// 	std::cout << "--------3. DELETE---------" << std::endl;
	delete d;
	return (0);
}

// Compilations Error: Abstract Class TEST and Pure Virtual Method
/* int	main()
{
	Animal	a;
	a.makeSound();
	return (0);
} */