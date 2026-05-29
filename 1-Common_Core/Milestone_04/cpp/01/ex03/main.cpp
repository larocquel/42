/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:18:41 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/29 19:33:15 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// My main

// int	main()
// {
// 	{
// 		Weapon	arsenal = Weapon("Knife");
// 		HumanA	filipe("Filipe", arsenal);
// 		filipe.attack();
// 		arsenal.setType("M4A4");
// 		filipe.attack();
// 	}
// 	{
// 		Weapon	arsenal = Weapon("Knife");
// 		HumanB	fernando("Fernando");
// 		fernando.attack();
// 		fernando.setWeapon(arsenal);
// 		fernando.attack();
// 		arsenal.setType("AK47");
// 		fernando.attack();
// 	}
// }