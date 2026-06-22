/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:20:43 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/07 14:43:42 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "------1. INSTANTIATE------" << std::endl;
	const Animal* A = new Animal();
	std::cout << std::endl;
	const Animal* D = new Dog();
	std::cout << std::endl;
	const Animal* C = new Cat();
	std::cout << std::endl;
	const WrongAnimal* WA = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* WC = new WrongCat();
	std::cout << std::endl;

	std::cout << "------2. TYPES------" << std::endl;
	std::cout << "Animal Type : " << A->getType() << std::endl;
	std::cout << "Dog Type    : " << D->getType() << std::endl;
	std::cout << "Cat Type    : " << C->getType() << std::endl;
	std::cout << "WAnimal Type: " << WA->getType() << std::endl;
	std::cout << "WCat Type   : " << WC->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "------3. SOUNDS------" << std::endl;
	std::cout << "Animal Sound    : ";
	A->makeSound();
	std::cout << "Dog Sound       : ";
	D->makeSound();
	std::cout << "Cat Sound       : ";
	C->makeSound();
	std::cout << "WAnimal Sound   : ";
	WA->makeSound();
	std::cout << "WCat Sound      : ";
	WC->makeSound();
	std::cout << std::endl;

	std::cout << "------4. DELETE------" << std::endl;
	delete A;
	std::cout << std::endl;
	delete D;
	std::cout << std::endl;
	delete C;
	std::cout << std::endl;
	delete WA;
	std::cout << std::endl;
	delete WC;
	std::cout << "Note: The WrongCat destructor is not being called." << std::endl;

	return (0);
}