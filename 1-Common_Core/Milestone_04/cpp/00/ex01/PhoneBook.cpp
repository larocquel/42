/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:50 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/27 20:47:43 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "My Awesome PhoneBook contructed!" << std::endl;
	_index = 0;
	_size = 0;
}

void	PhoneBook::print_index(int index)
{
	std::cout << '|' << std::setw(10) << index << '|';
}

void	PhoneBook::print_table(std::string text)
{
	int	len = text.length();

	if (len < 10)
	{
		for (int space = 10; space > len; space--)
			std::cout << '*';
		std::cout << text;
	}
	else
	{
		for (int letter = 0; letter < 9; letter++)
			std::cout << text[letter];
		std::cout << '.';
	}
	std::cout << '|';
}

void	PhoneBook::print_contact(int index)
{
	std::string	firstname = _phonebook[index].GetFirstName();
	std::string	lastname = _phonebook[index].GetLastName();
	std::string	nickname = _phonebook[index].GetNickName();
	std::string	phonenumber = _phonebook[index].GetPhoneNumber();
	std::string	darkestsecret = _phonebook[index].GetDarkestSecret();

	std::cout << "First Name : " << firstname << std::endl;
	std::cout << "Last Name  : " << lastname << std::endl;
	std::cout << "Nickname   : " << nickname << std::endl;
	std::cout << "Phonenumber: " << phonenumber << std::endl;
	std::cout << "D. Secret  : " << darkestsecret << std::endl;
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
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	if (_size == 0)
	{
		std::cout << "Empty phonebook. Try adding before searching!" << std::endl;
		return ;
	}

	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;

	for (int i = 0; i < _size; i++)
	{
		// index
		print_index(i);

		// firstname
		firstname = _phonebook[i].GetFirstName();
		print_table(firstname);

		// lastname
		lastname = _phonebook[i].GetLastName();
		print_table(lastname);

		// nickname;
		nickname = _phonebook[i].GetNickName();
		print_table(nickname);

		std::cout << std::endl;
	}

	// 2. Prompt for index and deal with out of range (reprompt?)
	std::string	index_str;
	int			index_int;
	while (true)
	{
		std::cout << "index: ";
		std::cin >> index_str;
		index_int = index_str[0] - '0';
		if (index_str.length() == 1 && (index_int >= 0 && index_int < _size))
		{
			print_contact(index_int);
			break;
		}
		else
		{
			std::cout << "Out of range. Try again!" << std::endl;
		}
	}

	// 3. IOMANIP (Input/Output manipulation?)
}