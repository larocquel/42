/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:18:41 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/30 16:17:14 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.hpp

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// OCF
		AForm();
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		// Parametrized Constructor
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);

		// Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Methods
		void		beSigned(const Bureaucrat& b);
		void		executeRequirements(const Bureaucrat& executor) const;


		// Virtual Pure Function
		virtual void execute(const Bureaucrat& executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Insert Operator Overload
std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif