/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:46 by leoaguia          #+#    #+#             */
/*   Updated: 2026/06/02 18:02:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fBits = 8;

	public:
		// Ortodox Canonical Form
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		// Other Constructors
		Fixed(const int n);
		Fixed(const float n);

		// Getter e Setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Type Converters
		int		toInt(void) const;
		float	toFloat(void) const;

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

		// Increment & Decrement Operators
		Fixed&	operator++(void);	// Pre
		Fixed	operator++(int);	// Post
		Fixed&	operator--(void);	// Pre
		Fixed	operator--(int);	// Post

		// Static Functions: Min & Max
        static Fixed& 		min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& 		max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Output stream insertion operator
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif