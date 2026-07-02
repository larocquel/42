/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:24:59 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/02 15:44:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern
{
	private:
		AForm*	makeShrubbery(const std::string& target) const;
		AForm*	makeRobotomy(const std::string& target) const;
		AForm*	makePresidential(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& formTarget);
};

#endif