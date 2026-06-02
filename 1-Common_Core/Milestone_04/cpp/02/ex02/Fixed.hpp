/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:46 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 17:12:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>

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
		int		toInt(void) const;				// Converts to Int
		float	toFloat(void) const;			// Converts to Float

		// Comparison Operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// Arithmetic Operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// Increment Operators
		Fixed&	operator++(void);
		Fixed	operator++(int);

		// Static Functions: Min & Max
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Output stream insertion operator
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif