/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:26:13 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 17:26:15 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.hpp

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		// Attribute
		std::string	_target;

	public:
		// OCF
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		// Parametrized Constructor
		RobotomyRequestForm(const std::string& target);

		// Virtual Pure Method from Base Class
		void	execute(const Bureaucrat& executor) const;

		// Auxiliar Method to print
		void	printRobot() const;
};

#endif