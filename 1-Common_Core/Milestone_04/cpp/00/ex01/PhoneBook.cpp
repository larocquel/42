/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:31:50 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/29 02:15:09 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "\n|      My Awesome PhoneBook constructed      |" << std::endl;
	_index = 0;
	_size = 0;
}

void	PhoneBook::print_index(int index)
{
	std::cout << '|' << std::right << std::setw(10) << index << '|';
}

void	PhoneBook::print_table(std::string text)
{
	int	len = text.length();

	if (len < 10)
	{
		std::cout << std::right << std::setw(10) << text;
	}
	else
	{
		std::cout << text.substr(0, 9) << '.';
	}
	std::cout << '|';
}

void	PhoneBook::print_contact(int index)
{
	std::cout << "First Name : " << _phonebook[index].GetFirstName() << std::endl;
	std::cout << "Last Name  : " << _phonebook[index].GetLastName() << std::endl;
	std::cout << "Nickname   : " << _phonebook[index].GetNickName() << std::endl;
	std::cout << "Phonenumber: " << _phonebook[index].GetPhoneNumber() << std::endl;
	std::cout << "D. Secret  : " << _phonebook[index].GetDarkestSecret() << std::endl;
}

std::string	PhoneBook::scan_input(std::string prompt)
{
	std::string	input = "";

	while(input.empty())
	{
		std::cout << std::left << std::setw(15) << prompt << ": ";
		std::getline(std::cin, input);
	}
	return (input);
}


void	PhoneBook::add(void)
{
	std::string	input;

	// FIRSTNAME
	input = scan_input("First Name");
	_phonebook[_index].SetFirstName(input);

	// LASTNAME
	input = scan_input("Last Name");
	_phonebook[_index].SetLastName(input);

	// NICKNAME
	input = scan_input("Nickname");
	_phonebook[_index].SetNickName(input);

	// PHONENUMBER
	input = scan_input("Phonenumber");
	_phonebook[_index].SetPhoneNumber(input);

	// DARKEST SECRET
	input = scan_input("Darkest Secret");
	_phonebook[_index].SetDarkestSecret(input);

	_index++;
	_size++;
	if (_index == 8)
		_index = 0;
	if (_size == 9)
		_size = 8;
}

void	PhoneBook::search(void)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	if (_size == 0)
	{
		std::cout << "Error: Empty phonebook. Try adding before searching!" << std::endl;
		return ;
	}

	std::cout << "|     Index|First Nam.| Last Name|  Nickname|" << std::endl;

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

	std::string	index;
	while (true)
	{
		std::cout << "\nindex: ";
		std::getline(std::cin, index);
		std::cout << "\n";
		if (index.length() == 1 && (index[0] - '0' >= 0 && index[0] - '0' < _size))
		{
			print_contact(index[0] - '0');
			break;
		}
		else
		{
			std::cout << "Error: Out of range. Try again!" << std::endl;
		}
	}
}