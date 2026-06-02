/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:46 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 09:42:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fBits = 8;

	public:
		// Ortodox Canonical Form
		Fixed();								// Constructor
		Fixed(const Fixed& other);				// Copy Constructor
		Fixed&	operator=(const Fixed& other);	// Copy Operator
		~Fixed();								// Destructor

		// Other Constructors
		Fixed(const int n);						// Int Constructor
		Fixed(const float n);					// Float Constructor

		// Getter e Setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Converters
		int		toInt(void);					// Converts to Int
		float	toFloat(void);					// Converts to Float
};

// Output stream insertion operator
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif