/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:49:25 by leoaguia          #+#    #+#             */
/*   Updated: 2026/05/04 18:51:00 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>	// std::cout << , std::cin >>
#include <iomanip>	// std::setw()
#include <cctype>	// toupper()
#include <algorithm>// std::transform(begin, end, save_local, any_operation)
class Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestsecret;

	public:
		void		SetFirstName(std::string firstname);
		void		SetLastName(std::string lastname);
		void		SetNickName(std::string nickname);
		void		SetPhoneNumber(std::string phonenumber);
		void		SetDarkestSecret(std::string darkestsecret);

		std::string GetFirstName(void)		const;
		std::string GetLastName(void)		const;
		std::string GetNickName(void)		const;
		std::string GetPhoneNumber(void)	const;
		std::string GetDarkestSecret(void)	const;
};

#endif