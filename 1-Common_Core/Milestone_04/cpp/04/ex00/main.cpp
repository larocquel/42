/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:55:22 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/06 20:21:26 by leoaguia         ###   ########.fr       */
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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // vai fazer som de gato!
    j->makeSound(); // vai fazer som de cachorro!
    meta->makeSound(); // vai fazer som de animal genérico!

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- TESTANDO WRONG ANIMAL ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    return 0;
}