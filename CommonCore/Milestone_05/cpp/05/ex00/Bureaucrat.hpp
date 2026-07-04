/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:01:25 by leoaguia          #+#    #+#             */
/*   Updated: 2026/07/03 20:25:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.hpp

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		// Attributes
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Parametrized Constructor
		Bureaucrat(const std::string& name, int grade);

		// Getters
		std::string	getName(void) const;
		int			getGrade(void) const;

		// Increment and Decrement Methods
		void		incrementGrade(void);
		void		decrementGrade(void);

		// Exceptions

		// High Grade Exception
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		// Low Grade Exception
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

// Overload Insertion
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif