/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:38:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 08:53:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>	// roundf()

class Fixed
{
	private:
		int					_value;
		static const int    _fBits = 8;

	public:
		// Orthodox Canonical Form
		Fixed();								// Default constructor
		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator
		~Fixed();								// Destructor

		// New Constructors
		Fixed(const int n);						// Int constructor
		Fixed(const float n);					// Float constructor

		// Getters and Setters
		int     getRawBits(void) const;
		void    setRawBits(int const raw);

		// Converters
		int     toInt(void) const;				// Converts to int
		float   toFloat(void) const;			// Converts to float
};

// Output stream insertion operator
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
