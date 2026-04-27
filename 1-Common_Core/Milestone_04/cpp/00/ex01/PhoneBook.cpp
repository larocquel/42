/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:50 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/26 20:40:56 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	_index = 0;
	_size = 0;
	std::cout << "My Awesome PhoneBook contructed!" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	input;

	// 1. Ler os 5 dados do usuário usando std::cin.
	std::cout << "Firstname      : ";
	std::cin >> input;
	// 2. Salvar esses dados na "ficha de papel" (objeto Contact) correta dentro do array _phonebook, usando os setters
	_phonebook[_index].SetFirstName(input);

	std::cout << "Lastname       : ";
	std::cin >>  input;
	_phonebook[_index].SetLastName(input);

	std::cout << "Nickname       : ";
	std::cin >> input;
	_phonebook[_index].SetNickName(input);

	std::cout << "Phonenumber    : ";
	std::cin >> input;
	_phonebook[_index].SetPhoneNumber(input);


	std::cout << "Darkest Secret : ";
	std::cin >> input;
	_phonebook[_index].SetDarkestSecret(input);


	// 3. Atualizar o _index para que o próximo contato vá para a gaveta seguinte.
	_index++;
	_size++;
	if (_index == 8)
		_index = 0;
	if (_size == 9)
		_size = 8;
}

void	PhoneBook::search(void)
{
	// 1. Lista de 4 colunas

	std::string	header = "|Index     |First Name|Last Name |Nickname  |";
	std::cout << header << std::endl;

	std::string	firstname;
	std::string	lastname;
	std::string	nickname;


	for (int i = 0; i < _size; i++)
	{
		// index
		std::cout << '|';
		std::cout << i;
		std::cout << "*********";
		std::cout << '|';

		// firstname
		int len = 0;
		firstname = _phonebook[i].GetFirstName();
		len = firstname.length();
		if (len < 10)
		{
			for (int space = 10; space > len; space--)
				std::cout << '*';
			std::cout << firstname;
		}
		else
		{
			for (int letter = 0; letter < 9; letter++)
				std::cout << firstname[letter];
			std::cout << '.';
		}
		std::cout << '|';

		// lastname
		lastname = _phonebook[i].GetLastName();
		len = lastname.length();
		if (len < 10)
		{
			for (int space = 10; space > len; space--)
				std::cout << '*';
			std::cout << lastname;
		}
		else
		{
			for (int letter = 0; letter < 9; letter++)
				std::cout << lastname[letter];
			std::cout << '.';
		}
		std::cout << '|';

		// nickname;
		nickname = _phonebook[i].GetNickName();
		len = nickname.length();
		if (len < 10)
		{
			for (int space = 10; space > len; space--)
				std::cout << '*';
			std::cout << nickname;
		}
		else
		{
			for (int letter = 0; letter < 9; letter++)
				std::cout << nickname[letter];
			std::cout << '.';
		}
		std::cout << '|' << std::endl;
	}

	// 2. Prompt for index and deal with out of range (reprompt?)

	// 3. IOMANIP (Input/Output manipulation?)
}