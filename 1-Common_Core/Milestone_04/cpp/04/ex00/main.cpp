/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:55:22 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 21:03:16 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "==================================================" << std::endl;
	std::cout << "       STAGE 1: CREATING POLYMORPHIC ANIMALS      " << std::endl;
	std::cout << "==================================================" << std::endl;

	std::cout << "[Creating Animal A...]" << std::endl;
	const Animal* A = new Animal();

	std::cout << "\n[Creating Dog D pointed by Animal*...]" << std::endl;
	const Animal* D = new Dog();

	std::cout << "\n[Creating Cat C pointed by Animal*...]" << std::endl;
	const Animal* C = new Cat();

	std::cout << "\n==================================================" << std::endl;
	std::cout << "       STAGE 2: TESTING TYPES AND SOUNDS          " << std::endl;
	std::cout << "==================================================" << std::endl;

	std::cout << "Dog pointer type report:  " << D->getType() << std::endl;
	std::cout << "Cat pointer type report:  " << C-> getType() << std::endl;
	std::cout << "A pointer type report: " << A->getType() << std::endl;

	std::cout << "\n[Calling makeSound() - Dynamic Binding in action]" << std::endl;
	std::cout << "C (Cat ptr) -> "; C-> makeSound();
	std::cout << "D (Dog ptr) -> "; D->makeSound();
	std::cout << "A (Animal) -> "; A->makeSound();

	std::cout << "\n==================================================" << std::endl;
	std::cout << "       STAGE 3: DELETING POLYMORPHIC ANIMALS      " << std::endl;
	std::cout << "==================================================" << std::endl;

	std::cout << "[Deleting A...]" << std::endl;
	delete A;

	std::cout << "\n[Deleting D (Dog)...]" << std::endl;
	delete D;

	std::cout << "\n[Deleting C (Cat)...]" << std::endl;
	delete C;

	std::cout << "\n==================================================" << std::endl;
	std::cout << "       STAGE 4: TESTING WRONG ANIMALS (NO VIRTUAL) " << std::endl;
	std::cout << "==================================================" << std::endl;

	std::cout << "[Creating WrongAnimal WA...]" << std::endl;
	const WrongAnimal* WA = new WrongAnimal();

	std::cout << "\n[Creating WrongCat WC pointed by WrongAnimal*...]" << std::endl;
	const WrongAnimal* WC = new WrongCat();

	std::cout << "\nWC pointer type report: " << WC-> getType() << std::endl;

	std::cout << "\n[Calling makeSound() - Static Binding in action]" << std::endl;
	std::cout << "WC (WrongCat ptr) -> "; WC-> makeSound();
	std::cout << "WA (WrongAnimal) -> "; WA->makeSound();

	std::cout << "\n==================================================" << std::endl;
	std::cout << "       STAGE 5: DELETING WRONG ANIMALS            " << std::endl;
	std::cout << "==================================================" << std::endl;

	std::cout << "[Deleting WA...]" << std::endl;
	delete WA;

	std::cout << "\n[Deleting WC (WrongCat) - Notice missing subclass destructor!]" << std::endl;
	delete WC;

	std::cout << "==================================================" << std::endl;

	return (0);
}