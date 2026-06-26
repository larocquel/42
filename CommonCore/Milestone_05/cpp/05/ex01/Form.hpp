/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:34:52 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/26 01:57:11 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.hpp

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// OCF
		Form();
		Form(const Form &other);
		Form&	operator=(const Form &other);
		~Form();

		// Parametrized Constructor
		Form(std::string &name, int gradeToSign, int gradeToExecute);

		// Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Methods
		bool		isValid(int grade);
		void		beSigned(Bureaucrat& b);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Override Insertion (<<) Operator
std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif