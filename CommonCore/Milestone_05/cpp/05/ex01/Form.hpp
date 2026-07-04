/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:33:01 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/04 14:58:53 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.hpp

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		// Attributes
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		// OCF
		Form();
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		// Parametrized Constructor
		Form(const std::string& name, int signGrade, int executeGrade);

		// Getters
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		// Functions
		void	beSigned(const Bureaucrat& b);

		// Exceptions

		// High Grade
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		// Low Grade
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

// Overload Insertion Operator
std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif