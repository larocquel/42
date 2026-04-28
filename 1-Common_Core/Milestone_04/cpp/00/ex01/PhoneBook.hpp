/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/28 03:30:00 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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