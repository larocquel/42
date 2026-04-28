/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:48:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/04/28 03:11:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// FirstName

void		Contact::SetFirstName(std::string firstname)
{
	_firstname = firstname;
}

std::string Contact::GetFirstName(void)		const
{
	return (_firstname);
}

// LastName

void		Contact::SetLastName(std::string lastname)
{
	_lastname = lastname;
}

std::string Contact::GetLastName(void)		const
{
	return (_lastname);
}

// NickName

void		Contact::SetNickName(std::string nickname)
{
	_nickname = nickname;
}

std::string Contact::GetNickName(void)		const
{
	return (_nickname);
}

// PhoneNumber

void		Contact::SetPhoneNumber(std::string phonenumber)
{
	_phonenumber = phonenumber;
}

std::string Contact::GetPhoneNumber(void)	const
{
	return (_phonenumber);
}

// Darkest Secret

void		Contact::SetDarkestSecret(std::string darkestsecret)
{
	_darkestsecret = darkestsecret;
}

std::string Contact::GetDarkestSecret(void)	const
{
	return (_darkestsecret);
}