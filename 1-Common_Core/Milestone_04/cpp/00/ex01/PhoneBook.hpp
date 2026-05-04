/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/04 18:51:39 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/* Auxiliar Method: (Every aux. met. is declared as private)*/

class	PhoneBook
{
	private:
	Contact		_phonebook[8];
	int			_index;
	int			_size;
	void		print_index(int index);
	void		print_table(std::string text);
	void		print_contact(int index);
	std::string	scan_input(std::string prompt);

	public:
	PhoneBook();
	void	add(void);
	void	search(void);
};

#endif