/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:33:47 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/27 19:44:25 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.hpp

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		// Ortodox Canonical Form
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&	operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Parametrized Constructor
		Bureaucrat(std::string const &name, int grade);

		// Getters
		std::string	getName() const;
		int			getGrade() const;

		// Methods
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form& form);

		// Exceptions (Nested Classes)
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
};

// Override Operator <<
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif