/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:38:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/01 21:39:49 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // roundf()

class Fixed
{
	private:
		int					_value;
		static const int	_fBits = 8;

	public:
		// Ortodox Canonical Form
		Fixed();								// Construtor
		Fixed(const Fixed& other);				// Copy Construtor de cópia
		Fixed& operator=(const Fixed& other);	// Copy Assignment Operator
		~Fixed();								// Destructor

		// New Constructors
		Fixed(const int n);						// Int Constructor
		Fixed(const float n);					// Float Constructor

		// Getter e Setter
		int     getRawBits(void) const;
		void    setRawBits(int const raw);

		// Converters
		int     toInt(void) const;				// Converts to int
		float   toFloat(void) const;			// Converts to float
};

#endif