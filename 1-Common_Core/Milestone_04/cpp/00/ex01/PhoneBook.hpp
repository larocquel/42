/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/28 02:13:10 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact		_phonebook[8]; // Duvida: Oq é um objeto?
	int			_index;
	int			_size;
	void		print_index(int index);			// Duvida: Por qual motivo esses métodos tem que ser privados?
	void		print_table(std::string text);
	void		print_contact(int index);

	public:
	PhoneBook();	// Duvida: O que é Constructor?
	void	add(void);
	void	search(void);
};