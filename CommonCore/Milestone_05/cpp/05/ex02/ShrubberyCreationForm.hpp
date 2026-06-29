/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:26 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/29 02:58:50 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.hpp

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		// Attributes
		std::string	_target;

	public:
		// OCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberryCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberryCreationForm& other);
		~ShrubberyCreationForm();

		// Virtual Pure Method from Base Class
		void execute(const Bureaucrat& executor) const;

};

#endif