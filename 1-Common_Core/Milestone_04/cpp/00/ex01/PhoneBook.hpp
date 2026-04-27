/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/26 20:36:40 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact	_phonebook[8];
	int		_index;
	int		_size;

	public:
	PhoneBook(); //	Constructor, inicializa o que for necessário
	void	add(void);
	void	search(void);
};