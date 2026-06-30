/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:26:03 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm.hpp

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		// Attribute
		std::string	_target;

	public:
		// OCF
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		// Parametrized Constructor
		PresidentialPardonForm(const std::string& target);

		// Virtual Pure Method from Base Class (Abstract)
		void	execute(const Bureaucrat& executor) const;
	};

#endif