/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:43:24 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/04 13:46:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
	private:

	public:
	// Ortodox Canonical Form
	ClapTrap();										// Constructor
	ClapTrap(const ClapTrap& other);				// Copy Contructor
	ClapTrap&	operator=(const ClapTrap& other);	// Copy Assignment Operator
	~ClapTrap();
};

#endif